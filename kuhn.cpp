/*
Kuhn's algorithm O(NM)
*/
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
	ll ans = 0;
	for (ll i = 1; i <= n; i++)
		mu[i] = go[i] = 0;
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= n; j++)
			w[j] = 0;
		ans += try_kuhn(i);
	}
}