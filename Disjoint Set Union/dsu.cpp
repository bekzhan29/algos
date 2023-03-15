/*
Disjoint Set Union O(1)
- init_dsu() O(N)
- fin() O(1)
- uni() O(1)
*/
ll p[N], r[N];
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
void init_dsu(ll n)
{
	for (ll i = 1; i <= n; i++)
		p[i] = i, r[i] = 1;
}