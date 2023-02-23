/*
Алгоритм Крускала O(MlogM)
*/
ll p[N + 10], r[N + 10], msz;
struct edge
{
	ll x, y, z;
	edge(ll x, ll y, ll z) : x(x), y(y), z(z) {}
} e[N + 10], mst[N + 10];
bool cmp(edge a, edge b)
{
	return a.z < b.z;
}
ll fin(ll a)
{
	if (a == p[a])
		return a;
	return p[a] = fin(p[a]);
}
void uni(ll a, ll b)
{
	a = fin(a), b = fin(b);
	if (a == b)
		return;
	if (r[a] > r[b])
		r[a] += r[b], p[b] = a;
	else
		r[b] += r[a], p[a] = b;
}
void kruskal()
{
	msz = 0;
	for (ll i = 1; i <= n; i++)
		p[i] = i, r[i] = 1;
	sort(e + 1, e + m + 1, &cmp);
	for (ll i = 1; i <= m; i++)
		if (fin(e[i].x) != fin(e[i].y))
			uni(e[i].x, e[i].y), mst[++msz] = e[i];
}
