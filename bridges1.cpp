/*
Поиск мостов в связном графе O(N+M)
Граф не содержит кратных рёбер
*/
ll cnt, w[N], dep[N], up[N];
pair<ll, ll> br[N];
vector<ll> v[N];
void dfs(ll x, ll pr, ll depth)
{
	dep[x] = up[x] = depth;
	w[x] = 1;
	for (ll to : v[x])
	{
		if (to == pr)
			continue;
		if (!w[to])
		{
			dfs(to, x, depth + 1);
			up[x] = min(up[x], up[to]);
			if (up[to] > dep[x])
				br[++cnt] = {x, to};
		}
		else
			up[x] = min(up[x], dep[to]);
	}
}
