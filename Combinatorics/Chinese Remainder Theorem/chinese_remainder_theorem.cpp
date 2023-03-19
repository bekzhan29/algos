ll sz, k[N], mi[N], rmi[N], re[N];
ll bin(ll a, ll n, ll m)
{
	ll ans = 1;
	while (n)
	{
		if (n & 1)
			ans *= a, ans %= m;
		a *= a, a %= m;
		n /= 2;
	}
	return ans;
}
ll phi(ll n)
{
	ll ans = n;
	for (ll i = 2; i * i <= n; i++)
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
ll CRM()
{
	// https://github.com/bekzhan29/algos
	ll m = 1, ans = 0;
	for (ll i = 1; i <= sz; i++)
		m *= k[i];
	for (ll i = 1; i <= sz; i++)
	{
		mi[i] = m / k[i];
		rmi[i] = bin(mi[i], phi(k[i]) - 1, k[i]);
		ans += re[i] * rmi[i] * mi[i];
		ans %= m;
	}
	return ans;
}