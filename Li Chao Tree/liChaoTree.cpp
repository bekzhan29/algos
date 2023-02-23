/*
Li Chao Tree O(NlogN)
- Добавить новую прямую O(logN)
- Найти ответ O(logN)
*/
const ll N = 1000100;
struct line
{
	ll k, b;
} t[4 * N];
void build(ll v, ll l, ll r)
{
	if (l == r)
	{
		t[v] = {INF, INF};
		return;
	}
	ll mid = (l + r) / 2;
	build(v * 2, l, mid);
	build(v * 2 + 1, mid + 1, r);
	t[v] = {INF, INF};
}
ll get(line l, ll x)
{
	return l.k * x + l.b;
}
void upd(ll v, ll l, ll r, line x)
{
	if (l == r)
	{
		if (get(x, l) <= get(t[v], l))
			t[v] = x;
		return;
	}
	ll mid = (l + r) / 2;
	ll left = get(x, l) <= get(t[v], l);
	ll middle = get(x, mid) <= get(t[v], mid);
	if (middle == 1)
		swap(t[v], x);
	if (left != middle)
		upd(v * 2, l, mid, x);
	else
		upd(v * 2 + 1, mid + 1, r, x);
}
line minn(ll v, ll l, ll r, ll x)
{
	if (l == r)
		return t[v], x;
	ll mid = (l + r) / 2;
	line y;
	if (x <= mid)
		y = minn(v * 2, l, mid, x);
	else
		y = minn(v * 2 + 1, mid + 1, r, x);
	if (get(t[v], x) <= get(y, x))
		return t[v];
	return y;
}
