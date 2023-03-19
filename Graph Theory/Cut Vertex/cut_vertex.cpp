ll cnt, w[N], dep[N], up[N], cut[N];
vector<ll> v[N];
void dfs(ll x, ll pr, ll depth)
{
	// https://github.com/bekzhan29/algos
	dep[x] = up[x] = depth;
	w[x] = 1;
	ll ch = 0, go = 0;
	for (ll to : v[x])
	{
		if (to == pr)
			continue;
		if (!w[to])
		{
			go++;
			dfs(to, x, depth + 1);
			up[x] = min(up[x], up[to]);
			if (up[to] >= dep[x])
				ch = 1;
		}
		else
			up[x] = min(up[x], dep[to]);
	}
	if (pr == 0)
		ch = go > 1;
	if (ch)
		cut[++cnt] = x;
}