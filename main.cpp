#include <iostream>
#include <fstream>
#include <random>

#include "matrix.h"
#include "Source.h"

using namespace std;

const int m=1319,n=166,l=166,q=4093,r=4,t=2;
const double alpha=0.0024;

//amnltrq

ofstream pl("plaintext.txt");
ofstream ci("ciphertext.txt");
ofstream rep("report.txt");

void output(matrix m)
{
	for(int i=0;i<m.n;i++)
	{
		for(int j=0;j<m.m;j++)
		{
			rep<<m[i][j]<<" ";
		}
		rep<<"\n";
	}
}

int main(void)
{
	

	int t;
	
	crypto cpt(alpha,m,n,l,t,r,q);

	cout<<"Please input the number of test cases.";
	cin>>t;

	pair<matrix,matrix> pub;
	matrix pri;
	
	pub=cpt.pub();
	pri=cpt.pri();

	rep<<"REPORT:\n";
	rep<<"\nA:\n";
	output(pub.first);
	rep<<"\nS:\n";
	output(pri);
	rep<<"\nB:\n";
	output(pub.second);
	rep<<"a: "<<a<<"\n";
	rep<<"m: "<<m<<"\n";
	rep<<"n: "<<n<<"\n";
	rep<<"l: "<<l<<"\n";
	rep<<"t: "<<t<<"\n";
	rep<<"r: "<<r<<"\n";
	rep<<"q: "<<q<<"\n";


	for(int i=0;i<t;i++)
	{
		matrix plt(l);


	}

	return 0;
}