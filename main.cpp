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

void output(ostream& out,matrix m)
{
	for(int i=0;i<m.n;i++)
	{
		for(int j=0;j<m.m;j++)
		{
			out<<m[i][j];

			if(m.m>1)
			{
				out<<" ";
			}
		}
		out<<"\n";
	}
}

void cmp(matrix l,matrix r)
{
	int cnt=0;

	for(int i=0;i<l.n;i++)
	{
		if(l[i][0]!=r[i][0])
		{
			rep<<"l: "<<l[i][0]<<" r: "<<r[i][0]<<"\n";
			cnt++;
		}
	}

	cout<<"\nwrong "<<cnt<<" in "<<l.n<<", "<<double(cnt*100)/double(l.n)<<"% right\n";
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
	output(rep,pub.first);
	rep<<"\nS:\n";
	output(rep,pri);
	rep<<"\nB:\n";
	output(rep,pub.second);
	rep<<"alpha: "<<alpha<<"\n";
	rep<<"m: "<<m<<"\n";
	rep<<"n: "<<n<<"\n";
	rep<<"l: "<<l<<"\n";
	rep<<"t: "<<t<<"\n";
	rep<<"r: "<<r<<"\n";
	rep<<"q: "<<q<<"\n";
	rep<<"\n================\n";

	for(int i=1;i<=t;i++)
	{
		matrix plt(l,0,2,UNIFORM);
		pair<matrix,matrix> ct=cpt.enc(plt);
		matrix pt2=cpt.dec(ct);

		rep<<"Case "<<i<<"\n\n";
		pl<<"Case "<<i<<"\n\n";
		ci<<"Case "<<i<<"\n\n";

		pl<<"u:\n";
		output(rep,ct.first);
		pl<<"c:\n";
		output(rep,ct.second);
		output(ci,plt);
		output(ci,pt2);
		
		rep<<"\n================\n";
		pl<<"\n================\n";
		ci<<"\n================\n";

		cmp(plt,pt2);
	}

	return 0;
}