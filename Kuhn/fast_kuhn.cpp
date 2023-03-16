ll mu[N], go[N], w[N];
vector<ll> v[N];
ll try_kuhn(ll x)
{
	if (w[x])
		return 0;
	w[x] = 1;
	for (ll to : v[x])
		if (!mu[to])
		{
			mu[to] = x;
			go[x] = to;
			return 1;
		}
	for (ll to : v[x])
		if (try_kuhn(mu[to]))
		{
			mu[to] = x;
			go[x] = to;
			return 1;
		}
	return 0;
}
void kuhn()
{
	// https://github.com/bekzhan29/algos
	ll ans = 0;
	for (ll i = 1; i <= n; i++)
		mu[i] = go[i] = 0;
	for (ll ch = 1; ch;)
	{
		ch = 0;
		for (ll i = 1; i <= n; i++)
			w[i] = 0;
		for (ll i = 1; i <= n; i++)
			if (go[i] == 0 && try_kuhn(i))
				ans++, ch = 1;
	}
}