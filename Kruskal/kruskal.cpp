/*
https://github.com/bekzhan29/algos/

Алгоритм Крускала O(MlogM)
*/
ll p[N], r[N], msz;
struct edge
{
	ll x, y, w;
	edge(ll x = 0, ll y = 0, ll w = 0) : x(x), y(y), w(w) {}
} e[N], mst[N];
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}
void init_dsu(ll n)
{
	for (ll i = 1; i <= n; i++)
		p[i] = i, r[i] = 1;
}
ll fin(ll a)
{
	if (a == p[a])
		return a;
	return p[a] = fin(p[a]);
}
bool uni(ll a, ll b)
{
	a = fin(a), b = fin(b);
	if (a == b)
		return 0;
	if (r[a] > r[b])
		r[a] += r[b], p[b] = a;
	else
		r[b] += r[a], p[a] = b;
	return 1;
}
void kruskal(ll n, ll m)
{
	init_dsu(n);
	msz = 0;
	sort(e + 1, e + m + 1, &cmp);
	for (ll i = 1; i <= m; i++)
		if (uni(e[i].x, e[i].y))
			mst[++msz] = e[i];
}