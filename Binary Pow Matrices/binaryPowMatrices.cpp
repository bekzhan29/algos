/*
Бинарное возведение матрицы A размера NxN в степень M O(N^3*logM)
*/
void bpow(ll n, ll m)
{
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= n; j++)
			res[i][j] = (i == j);
	while (m)
	{
		if (m & 1)
		{
			for (ll i = 1; i <= n; i++)
				for (ll j = 1; j <= n; j++)
				{
					c[i][j] = 0;
					for (ll k = 1; k <= n; k++)
						c[i][j] += res[i][k] * a[k][j], c[i][j] %= mod;
				}
			for (ll i = 1; i <= n; i++)
				for (ll j = 1; j <= n; j++)
					res[i][j] = c[i][j];
		}
		for (ll i = 1; i <= n; i++)
			for (ll j = 1; j <= n; j++)
			{
				c[i][j] = 0;
				for (ll k = 1; k <= n; k++)
					c[i][j] += a[i][k] * a[k][j], c[i][j] %= mod;
			}
		for (ll i = 1; i <= n; i++)
			for (ll j = 1; j <= n; j++)
				a[i][j] = c[i][j];
		m /= 2;
	}
}
