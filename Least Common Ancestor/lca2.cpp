/*
Наименьший общий предок
Поиск деревом отрезков O(logN)
*/
ll sz, pos[N], ord[2 * N], dep[2 * N];
pll tree[8 * N];
vector<ll> v[N];
void dfs(ll x, ll par, ll depth)
{
	ord[++sz] = x;
	dep[sz] = depth;
	pos[x] = sz;
	for (ll to : v[x])
		if (to != par)
		{
			dfs(to, x, depth + 1);
			ord[++sz] = x;
			dep[sz] = depth;
		}
}
void build(ll v, ll l, ll r)
{
	if (l == r)
	{
		tree[v] = {dep[l], l};
		return;
	}
	ll mid = (l + r) / 2;
	build(v * 2, l, mid);
	build(v * 2 + 1, mid + 1, r);
	tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
}
void init(ll root)
{
	sz = 0;
	dfs(root, 0, 1);
	build(1, 1, sz);
}
pll minn(ll v, ll l, ll r, ll x, ll y)
{
	if (x > y || x > r || y < l)
		return {INF, 0};
	if (x <= l && r <= y)
		return tree[v];
	ll mid = (l + r) / 2;
	return min(minn(v * 2, l, mid, x, y), minn(v * 2 + 1, mid + 1, r, x, y));
}
ll lca(ll x, ll y)
{
	if (pos[x] > pos[y])
		swap(x, y);
	pll ans = minn(1, 1, sz, pos[x], pos[y]);
	return ord[ans.se];
}