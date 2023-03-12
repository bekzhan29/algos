/*
Биномиальные коэффициенты O(N^2)
*/
struct cnk
{
private:
	int n;
	vector<vector<int>> a;

public:
	void init_cnk(int n)
	{
		this->n = n;
		a.resize(n + 1);
		for (int i = 0; i <= n; i++)
			a[i].resize(n + 1);
		a[0][0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= i; j++)
			{
				a[i][j] = a[i - 1][j];
				if (j)
					a[i][j] += a[i - 1][j - 1];
				if (a[i][j] >= mod)
					a[i][j] -= mod;
			}
	}
	int c(int n, int k)
	{
		if (k > n || k < 0 || n < 0)
			return 0;
		return a[n][k];
	}
};