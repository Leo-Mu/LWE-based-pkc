#ifndef MATRIX_HPP
#define MATRIX_HPP 1

#include <iostream>
#include <random>
#include <cmath>
#include <vector>

#define GAUSS 1
#define UNIFORM 0
#define EMPTY -1

#define M_PI		3.14159265358979323846
#define M_PI_2		1.57079632679489661923
#define M_PI_4		0.78539816339744830962
#define M_1_PI		0.31830988618379067154
#define M_2_PI		0.63661977236758134308
#define M_2_SQRTPI	1.12837916709551257390
#define M_SQRT2 	1.41421356237309504880

typedef long long ll;
typedef long double ld;

//template// <int n,int m>
class matrix //(const int& n,int m,int q=998244353,int rd=UNIFORM,double sig=0.0)
{
	public:
		int n,m;
		matrix(int n=0,int m=1,int q=998244353,int rd=EMPTY,double sig=0.0);
		matrix(const matrix& m);

		std::vector<ll>& operator[](int i);
		const std::vector<ll>& operator[](int i) const;
		matrix& operator=(matrix a);
		matrix operator~(void);
		friend matrix operator+(matrix a,matrix b);
		friend matrix operator-(matrix a,matrix b);
		friend matrix operator*(matrix a,matrix b);

		friend matrix f(matrix mx,int q_,int t_);

	private:
		int q,rd;
		double sig;
		int mod;
		std::vector<std::vector<ll> > v;
};

//friend matrix matrix::operator~(matrix a)



matrix::matrix(int _n,int _m,int _q,int _rd,double _sig): n(_n),m(_m),q(_q),rd(_rd),sig(_sig),v(_n,std::vector<ll>(_m))
{

	if(rd==GAUSS)
	{
	std::random_device seed;
	std::default_random_engine gen{seed()};
		std::normal_distribution<double> rd(0.0,sig);

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				v[i][j]=ll(round(rd(gen)))%q;
			}
		}
	}
	else if(rd==UNIFORM)
	{
	std::random_device seed;
	std::default_random_engine gen{seed()};
		std::uniform_int_distribution<int> rd(0,q-1);

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				v[i][j]=ll(rd(gen));
			}
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				v[i][j]=0LL;
			}
		}
	}
}
matrix::matrix(const matrix& b): n(b.n),m(b.m),q(b.q),rd(b.rd),sig(b.sig),v(b.v) {}

std::vector<ll>& matrix::operator[](int i)
{
	return v[i];
}
const std::vector<ll>& matrix::operator[](int i) const
{
	return v[i];
}

matrix& matrix::operator=(matrix a)
{
	n=a.n;
	m=a.m;
	q=a.q;
	rd=a.rd;
	sig=a.sig;

	v.resize(n);

	for(int i=0;i<n;i++)
	{
		v[i].resize(m);
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

matrix operator+(matrix a,matrix b)
{
	matrix tmp(a);

	for(int i=0;i<a.n;i++)
	{
		for(int j=0;j<a.m;j++)
		{
			tmp[i][j]=a[i][j]+b[i][j];
		}
	}

	return tmp;
}
matrix operator-(matrix a,matrix b)
{
	matrix tmp(a);

	for(int i=0;i<a.n;i++)
	{
		for(int j=0;j<b.n;j++)
		{
			tmp[i][j]=a[i][j]-b[i][j];
		}
	}

	return tmp;
}
matrix operator*(matrix a,matrix b)
{
	matrix tmp(a.n,b.m,a.q);

	for(int i=0;i<a.n;i++)
	{
		for(int j=0;j<b.m;j++)
		{
			for(int k=0;k<a.m;k++)
			{
				tmp[i][j]+=a[i][k]*b[k][j];
			}
		}
	}

	return tmp;
}

matrix f(matrix mx,int q_,int t_)
{
	matrix tmp(mx);
	for(int i=0;i<tmp.n;i++)
	{
		for(int j=0;j<tmp.m;j++)
		{
			tmp[i][j]=ll(round(ld(tmp[i][j])*ld(q_)/ld(t_)));
		}
	}

	return tmp;
}

#endif
