/*
Наименьший общий предок
Поиск двоичным подьемом O(logN)
*/
const ll lg = 17;
ll pr[lg][N], tin[N], tout[N], tim;
vector<ll> v[N];
void dfs(ll x, ll par)
{
	tin[x] = ++tim;
	pr[0][x] = par;
	if (par == 0)
		pr[0][x] = x;
	for (ll i = 1; i < lg; i++)
		pr[i][x] = pr[i - 1][pr[i - 1][x]];
	for (ll to : v[x])
		if (to != par)
			dfs(to, x);
	tout[x] = tim;
}
ll lca(ll x, ll y)
{
	ll ans = x;
	for (ll i = lg - 1; i >= 0; i--)
		if (tin[pr[i][ans]] > tin[y] || tout[y] > tout[pr[i][ans]])
			ans = pr[i][lca];
	if (tin[ans] > tin[y] || tout[y] > tout[ans])
		ans = pr[0][ans];
	return ans;
}
void init(ll root)
{
	dfs(root, 0);
}