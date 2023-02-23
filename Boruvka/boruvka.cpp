/*
Алгоритм Борувки O(MlogN)
e[N] - ребра
mst[N] - ребра в минимальном оставном дереве
*/
ll n, m, p[N], r[N], msz;
pair<ll, ll> minn[N];
struct edge
{
	ll x, y, w;
} e[N], mst[N];
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
void boruvka(ll n, ll m)
{
	init_dsu(n);
	msz = 0;
	ll n_cmp = n;
	for (; n_cmp > 1;)
	{
		for (ll i = 1; i <= n; i++)
			minn[i] = {INF, 0};
		for (ll i = 1; i <= m; i++)
		{
			ll x = fin(e[i].x), y = fin(e[i].y), weight = e[i].w;
			if (x == y)
				continue;
			minn[x] = min(minn[x], {weight, i});
			minn[y] = min(minn[y], {weight, i});
		}
		for (ll i = 1; i <= n; i++)
		{
			if (i != fin(i))
				continue;
			ll pos = minn[i].se;
			if (uni(e[pos].x, e[pos].y))
			{
				mst[++msz] = e[pos];
				n_cmp--;
			}
		}
	}
}