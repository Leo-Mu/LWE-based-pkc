#include<iostream>
#include<random>
#include<vector>
#include<math.h>
#include"matrix.h"
using namespace std;


void oneRound(int a, int m, int n, int l, int t, int r, int q)
{

}

pair< pair<matrix, matrix>, matrix> gen(int a, int m, int n, int l, int q)
{
	matrix A(m, n, q, UNIFORM), S(n, l, q, UNIFORM), E(m, l, q, GAUSS, (double)a*q / (M_PI * M_SQRT2));
	matrix B = A * S + E;
	return pair< pair<matrix, matrix>, matrix>(pair<matrix, matrix>(A, B), S);
}

pair< matrix, matrix> enc(pair<matrix, matrix>pub, int m, int r, int t, int l, int q)
{
	matrix v(l, 1, t, UNIFORM), R(m, 1, 2 * r + 1,UNIFORM);
	for (int i = 0; i < m; i++)
	{
		R[i][0] -= r;
	}
	matrix u = (~(pub.first))*R, c = (~(pub.second))*R + f(v, q);
	return pair<matrix, matrix>(u, c);
}

matrix dec(int t, pair<matrix, matrix>uc, matrix s)
{
	return f((uc.second - s * uc.first), t);
}

int main(void)
{
	/*double mu{ 50.0 }, sigma{ 10.0 };
	normal_distribution<> norm{ mu, sigma };
	random_device rd;
	default_random_engine rng{ rd() };
	for (int i = 0; i < 1000; i++)
	{
		cout << round(norm(rng)) << endl;
	}*/
	int t = 2;
	return 0;
}
