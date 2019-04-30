#include<iostream>
#include<random>
#include<vector>
using namespace std;

template<int m,int n>
class matrix
{
public:
	matrix();
	
private:
	int mod;
	vector<vector<int> > v(m, vector<int>(n));
};

template<int m, int n>
matrix<m, n>::matrix()
{

}

int main(void)
{
	double mu{ 50.0 }, sigma{ 10.0 };
	normal_distribution<> norm{ mu, sigma };
	random_device rd;
	default_random_engine rng{ rd() };
	for (int i = 0; i < 1000; i++)
	{
		cout << round(norm(rng)) << endl;
	}
	//cout << "Normally distributed values: " << norm(rng) << " " << norm(rng) << std::endl;
	return 0;
}


