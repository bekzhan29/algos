int bin_pow(int a, int n, int m)
{
	int ans = 1;
	while (n)
	{
		if (n & 1)
			ans = 1LL * ans * a % m;
		a = 1LL * a * a % m;
		n /= 2;
	}
	return ans;
}
template <typename Type>
struct cnk
{
	// https://github.com/bekzhan29/algos
private:
	int n;
	vector<int> f, rf;

public:
	void init_cnk(int n)
	{
		this->n = n;
		f.resize(n + 1);
		rf.resize(n + 1);
		f[0] = 1;
		for (int i = 1; i <= n; i++)
			f[i] = 1LL * f[i - 1] * i % mod;
		rf[n] = bin_pow(f[n], mod - 2, mod);
		for (int i = n - 1; i >= 0; i--)
			rf[i] = 1LL * rf[i + 1] * (i + 1) % mod;
	}
	Type c(int n, int k)
	{
		if (k > n || k < 0 || n < 0)
			return 0;
		return 1LL * f[n] * rf[k] % mod * rf[n - k] % mod;
	}
};