/*
https://github.com/bekzhan29/algos/

Centroid Decomposition
*/
ll used[N], cnt[N];
vector<ll> v[N], pr[N];
void dfs(ll x, ll par)
{
	cnt[x] = 1;
	for (ll to : v[x])
	{
		if (to == par || used[to])
			continue;
		dfs(to, x);
		cnt[x] += cnt[to];
	}
}
void dfs1(ll root, ll x, ll par)
{
	pr[x].pb(root);
	for (ll to : v[x])
	{
		if (to == par || used[to])
			continue;
		dfs1(root, to, x);
	}
}
void cen(ll x)
{
	dfs(x, 0);
	ll sz = cnt[x];
	for (ll ch = 1; ch;)
	{
		ch = 0;
		for (ll to : v[x])
			if (cnt[to] < cnt[x] && cnt[to] > sz / 2)
			{
				ch = 1;
				x = to;
				break;
			}
	}
	used[x] = 1;
	dfs1(x, x, 0);
	for (ll to : v[x])
		if (!used[to])
			cen(to);
}