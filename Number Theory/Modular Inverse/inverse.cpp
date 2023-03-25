int bin_pow(int a, int n, int m)
{
	// https://github.com/bekzhan29/algos
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
int phi(int n)
{
	int ans = n;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
		{
			while (n % i == 0)
				n /= i;
			ans -= ans / i;
		}
	if (n > 1)
		ans -= ans / n;
	return ans;
}
// m не простое
int inverse(int a, int m)
{
	return bin_pow(a, phi(m) - 1, m);
}
// m простое
int inverse_prime(int a, int m)
{
	return bin_pow(a, m - 2, m);
}