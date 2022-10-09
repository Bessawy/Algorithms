// karatsuba Multiplication
#include "main.h"


// arr size 4: contains a-b-c-d
void abcd(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d, vector<int> x, vector<int> y)
{
	auto begin_x = x.begin();
	auto mid_x = x.begin() + x.size() - x.size() / 2;
	auto end_x = x.end();

	copy(begin_x, mid_x, a.begin());
	copy(mid_x, end_x, b.begin());

	auto begin_y = y.begin();
	auto mid_y = y.begin() + y.size() - y.size() / 2;
	auto end_y = y.end();

	copy(begin_y, mid_y, c.begin());
	copy(mid_y, end_y, d.begin());
}

// Add two int vectors
vector<int> sum_vec(vector<int> x, vector<int> y)
{
	int r = 0;
	int num = 0;
	vector<int> sum;
	vector<int> add_y;
	vector<int> add_x;

	if (y.size() < x.size())
	{
		int diff = x.size() - y.size();
		for (int i = 0; i < diff; i++)
		{
			add_y.push_back(0);
		}
	}


	if (x.size() < y.size())
	{
		int diff = y.size() - x.size();
		for (int i = 0; i < diff; i++)
		{
			add_x.push_back(0);
		}
	}

	for (int i = 0; i < y.size(); i++)
	{
		add_y.push_back(y[i]);
	}

	for (int i = 0; i < x.size(); i++)
	{
		add_x.push_back(x[i]);
	}



	for (int i = add_x.size() - 1; i >= 0; --i)
	{
		num = add_x[i] + add_y[i] + r;
		if (num > 9)
		{
			num = num % 10;
			r = 1;
		}
		else
		{
			r = 0;
		}
		sum.push_back(num);
	}
	if (r == 1)
	{
		sum.push_back(1);
	}
	reverse(sum.begin(), sum.end());
	return sum;

}

// Sub two int vectors: assumes x>y always
vector<int> sub_vec(vector<int> x, vector<int> y)
{
	vector<int> sub_;

	if (y.size() < x.size())
	{
		int diff = x.size() - y.size();
		for (int i = 0; i < diff; i++)
		{
			sub_.push_back(0);
		}
	}

	for (int i = 0; i < y.size(); i++)
	{
		sub_.push_back(y[i]);
	}


	int r = 0;
	int num = 0;
	vector<int> sub;
	for (int i = x.size() - 1; i >= 0; --i)
	{ 
		int val = x[i] - r;
		if (val - sub_[i] >= 0)
		{
			r = 0;
			num = val - sub_[i];
		}
		else
		{
			val = val + 10;
			num = val - sub_[i];
			r = 1;
		}
		sub.push_back(num);
	}


	reverse(sub.begin(), sub.end());
	return sub;

}

// Multiple two int vectors: vectors assumed to have small size
vector<int> multi_vec(vector<int> x, vector<int> y)
{
	int x_ = 0;
	int y_ = 0;
	int prod = 0;
	vector<int> multi;

	for (int i = 0 ; i < x.size(); ++i)
	{
		x_ = x_ * 10 + x[i];
	}

	for (int i = 0; i < y.size(); ++i)
	{
		y_ = y_ * 10 + y[i];
	}

	prod = x_ * y_;

	while (1)
	{
		if (prod == 0)
			break;

		multi.push_back(prod % 10);
		prod = prod / 10;
	}

	reverse(multi.begin(), multi.end());
	return multi;
}

vector<int> pow_10(vector<int>& x, int n)
{
	vector<int> prod;
	for (int i = 0; i < x.size(); ++i)
	{
		prod.push_back(x[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		prod.push_back(0);
	}
	
	return prod;
}

vector<int> kara_Multi(vector<int> x, vector<int> y)
{
	if (x.size() < 3)
	{
		return  multi_vec(x, y);
	}

	vector<int> a(x.size() - x.size() / 2), b(x.size() / 2),
	c(y.size() - y.size() / 2), d(y.size() / 2);
	abcd(a, b, c, d, x, y);


	vector<int> ac = kara_Multi(a, c);
	vector<int> bd = kara_Multi(b, d);
	// a + b
	vector<int> a_b = sum_vec(a, b);
	// c + d
	vector<int> c_d = sum_vec(c, d);
	// (a+b)(c+d)
	vector<int> ab_cd = kara_Multi(a_b, c_d);
	// (a+b)(c+d) - ac - bd
	vector<int> abcd = sub_vec(sub_vec(ab_cd, ac), bd);
	// pow(10,n) * ac
	vector<int> ac_10;
	if(x.size() % 2 != 0)
		ac_10 = pow_10(ac, x.size() - 1);
	else
		ac_10 = pow_10(ac, x.size());
	//ac + pow(10, n/2)
	vector<int> abcd_10 = pow_10(abcd, x.size()/2);

	vector<int> fir = sum_vec(ac_10, abcd_10);
	vector<int> sec = sum_vec(fir, bd);
	//return  pow(10, n) * ac + pow(10, n/2) * abcd + bd;
	return sec;
}
