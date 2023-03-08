/*
Бинарное возведение матрицы A размера NxN в степень K O(N^3*logK)
*/
struct matrix
{
	ll n, m, p;
	vector<vector<ll>>a;
	void resize(ll n, ll m, ll p)
	{
		this->n = n;
		this->m = m;
		this->p = p;
		a.resize(n);
		for (ll i = 0; i < n; i++)
		{
			a[i].resize(m);
			for (ll j = 0; j < m; j++)
				a[i][j] = 0;
		}
	}
	matrix(int n = 1, int m = 1, int p = 2)
	{
		resize(n, m, p);
	}
	matrix &operator*=(const matrix &b)
	{
		assert(m == b.n);
		matrix c(n, b.m, p);
		for (ll i = 0; i < n; i++)
			for (ll j = 0; j < b.m; j++)
				for (ll k = 0; k < m; k++)
				{
					c.a[i][j] += 1LL * a[i][k] * b.a[k][j] % p;
					if (c.a[i][j] >= p)
						c.a[i][j] -= p;
				}
		n = c.n;
		m = c.m;
		a = c.a;
		return *this;
	}
};
matrix bin(matrix a, ll k)
{
	assert(a.n == a.m);
	matrix ans(a.n, a.n, a.p);
	for (ll i = 0; i < ans.n; i++)
		ans.a[i][i] = 1;
	while (k)
	{
		if (k & 1)
			ans *= a;
		a *= a;
		k /= 2;
	}
	return ans;
}