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