/*
Дерево Фенвика O(NlogN)
- Сумма на отрезке O(logN)
- upd(l, r) += k O(logN)
*/
ll tree[2][N];
void add2(ll ty, ll pos, ll x)
{
	for (; pos <= n; pos = (pos | (pos + 1)))
		tree[ty][pos] += x;
}
void add(ll l, ll r, ll x)
{
	add2(0, l, x);
	add2(0, r + 1, -x);
	add2(1, l, (1 - l) * x);
	add2(1, r + 1, r * x);
}
ll sum2(ll ty, ll pos)
{
	ll ans = 0;
	for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
		ans += tree[ty][pos];
	return ans;
}
ll sum(ll l, ll r)
{
	return sum2(0, r) * r - sum2(0, l - 1) * (l - 1) + sum2(1, r) - sum2(1, l - 1);
}
void build()
{
	for (ll i = 0; i <= n; i++)
		tree[0][i] = tree[1][i] = 0;
	for (ll i = 1; i <= n; i++)
		add2(1, i, a[i]);
}