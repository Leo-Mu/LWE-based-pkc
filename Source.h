#include<iostream>
#include<random>
#include<vector>
#include<math.h>
#include"matrix.h"
using namespace std;

class crypto
{
public:
	crypto(double a, int m, int n, int l, int t, int r, int q);
	pair<matrix, matrix> enc(matrix v);
	matrix dec(pair<matrix, matrix>uc);
	pair<matrix, matrix> pub(void);
	matrix pri(void);
private:
	matrix A, E, B, S;
	double a;
	int m, n, l, t, r, q;
};

crypto::crypto(double a_, int m_, int n_, int l_, int t_, int r_, int q_)
	:A(m_, n_, q_, UNIFORM), S(n_, l_, q_, UNIFORM), E(m_, l_, q_, GAUSS, (double)a_*q_ / (M_PI * M_SQRT2)),
	a(a_), m(m_), n(n_), l(l_), t(t_), r(r_), q(q_)
{
	B = A * S + E;
}

pair<matrix, matrix> crypto::enc(matrix v)
{
	matrix R(m, 1, 2 * r + 1, UNIFORM);
	for (int i = 0; i < m; i++)
	{
		R[i][0] -= r;
	}
	matrix u = (~A)*R, c = (~B)*R + f(v, q);
	return pair<matrix, matrix>(u, c);
}

matrix crypto::dec(pair<matrix, matrix> uc)
{
	return f((uc.second - S * uc.first), t);
}

pair<matrix, matrix> crypto::pub(void)
{
	return pair<matrix, matrix>(A, B);
}

matrix crypto::pri(void)
{
	return S;
}
