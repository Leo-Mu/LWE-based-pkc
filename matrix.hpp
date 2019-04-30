#ifndef MATRIX_HPP
#define MATRIX_HPP 1

//#include <iostream>
#include <random>
#include <cmath>
#include <vector>

#define GAUSS 1
#define UNIFORM 0

//template// <int n,int m>
class matrix //(const int& n,int m,int q=998244353,int rd=UNIFORM,double sig=0.0)
{
	public:
		matrix(int n=0,int m=0,int q=998244353,int rd=UNIFORM,double sig=0.0);

		std::vector<int>& operator[](int i);
		const std::vector<int>& operator[](int i) const;
		matrix& operator=(matrix a);
		matrix operator~(void);
		friend matrix operator!(matrix a);

		
	private:
		int n,m,q,rd;
		double sig;
		int mod;
		std::vector<std::vector<int> > v;
};

//friend matrix matrix::operator~(matrix a)



matrix::matrix(int _n,int _m,int _q,int _rd,double _sig): n(_n),m(_m),q(_q),rd(_rd),sig(_sig),v(_n,std::vector<int>(_m))
{
	std::random_device seed;
	std::default_random_engine gen{seed()};

	if(rd==GAUSS)
	{
		std::normal_distribution<double> rd(0.0,sig);

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				v[i][j]=int(round(rd(gen)))%q;
			}
		}
	}
	else
	{
		std::uniform_int_distribution<int> rd(0,q-1);

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				v[i][j]=rd(gen);
			}
		}
	}
}

std::vector<int>& matrix::operator[](int i)
{
	return v[i];
}
const std::vector<int>& matrix::operator[](int i) const
{
	return v[i];
}

matrix& matrix::operator=(matrix a)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			v[i][j]=a[i][j];
		}
	}

	return *this;
}


matrix matrix::operator~(void)
{
	matrix tmp(m,n,q,rd,sig);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			tmp[j][i]=v[i][j];
		}
	}

	return tmp;
}

#endif
