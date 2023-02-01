/*
Disjoint Set Union O(1)
*/
ll p[N + 10], r[N + 10];
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
void dsu()
{
	for (ll i = 1; i <= n; i++)
		p[i] = i, r[i] = 1;
}
