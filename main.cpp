#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

#include "matrix.h"
#include "Source.h"

using namespace std;

const int m=1042,n=233,l=233,q=32749,r=37,t=2;
const double alpha=0.000217;

//amnltrq

ofstream key("key.txt");
ofstream ci("ciphertext.txt");
ofstream rep("report.txt");

void output(ostream& out,matrix m)
{
	for(int i=0;i<m.n;i++)
	{
		for(int j=0;j<m.m;j++)
		{
			out<<m[i][j];
			out<<" ";
		}
		if(m.m>1)
		{
			out<<"\n";
		}
	}
	out<<"\n";
}

int cmp(matrix l,matrix r)
{
	int cnt=0;

	for(int i=0;i<l.n;i++)
	{
		if(l[i][0]!=r[i][0])
		{
			rep<<"pos: "<<i<<" l: "<<l[i][0]<<" r: "<<r[i][0]<<"\n";
			cnt++;
		}
	}

	//cout<<"\nwrong "<<cnt<<" in "<<l.n<<", "<<double((l.n-cnt)*100)/double(l.n)<<"% right\n";
	rep<<"\nwrong "<<cnt<<" in "<<l.n<<", "<<double((l.n-cnt)*100)/double(l.n)<<"% right\n";

	return cnt;
}

int main(void)
{
	srand(time(NULL));

	int cs,cnt=0;
	
	crypto cpt(alpha,m,n,l,t,r,q);

	cout<<"Please input the number of test cases: ";
	cin>>cs;

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

	for(int i=1;i<=cs;i++)
	{
		matrix plt(l,1,2,UNIFORM);
		pair<matrix,matrix> ct=cpt.enc(plt);
		matrix pt2=cpt.dec(ct);

		rep<<"Case "<<i<<"\n\n";
		key<<"Case "<<i<<"\n\n";
		ci<<"Case "<<i<<"\n\n";

		ci<<"u:\n";
		output(ci,ct.first);
		ci<<"c:\n";
		output(ci,ct.second);
		key<<"plt\n\n";
		output(key,plt);
		key<<"pt2\n";
		output(key,pt2);
		
		cnt+=cmp(plt,pt2);

		rep<<"\n================\n";
		key<<"\n================\n";
		ci<<"\n================\n";
	}

	cout<<"\ntotal wrong "<<cnt<<" in "<<l*cs<<", "<<double((l*cs-cnt)*100)/double(l*cs)<<"% right\n";
	rep<<"\ntotal wrong "<<cnt<<" in "<<l*cs<<", "<<double((l*cs-cnt)*100)/double(l*cs)<<"% right\n";


	return 0;
}