/*
Поиск мостов в связном графе O(N+M)
Граф не содержит кратных рёбер
*/
ll cnt, w[N + 10], dep[N + 10], up[N + 10];
pair<ll, ll> br[N + 10];
vector<ll> v[N + 10];
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
