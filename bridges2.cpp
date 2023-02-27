/*
Поиск мостов в связном графе O(N+M)
Граф может содержать кратные рёбра
*/
struct edge
{
	ll x, y, ind;
	edge(ll x = 0, ll y = 0, ll ind = 0) : x(x), y(y), ind(ind) {}
} br[N];
ll cnt, w[N], dep[N], up[N];
vector<edge> v[N];
void dfs(ll x, ll last, ll depth)
{
	dep[x] = up[x] = depth;
	w[x] = 1;
	for (edge e : v[x])
	{
		if (e.ind == last)
			continue;
		ll to = e.y;
		if (!w[to])
		{
			dfs(to, e.ind, depth + 1);
			up[x] = min(up[x], up[to]);
			if (up[to] > dep[x])
				br[++cnt] = e;
		}
		else
			up[x] = min(up[x], dep[to]);
	}
}
