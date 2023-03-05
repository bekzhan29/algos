/*
Дерево отрезков сверху вниз
- a[x] += y
- sum(l, r)
*/
struct segment_tree{
	ll tree[4 * N];
	void build(ll v, ll l, ll r, ll *a)
	{
		if (l == r)
		{
			tree[v] = a[l];
			return;
		}
		ll mid = (l + r) / 2;
		build(v * 2, l, mid, a);
		build(v * 2 + 1, mid + 1, r, a);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
	void upd(ll v, ll l, ll r, ll pos, ll k)
	{
		if (l == r)
		{
			tree[v] += k;
			return;
		}
		ll mid = (l + r) / 2;
		if (pos <= mid)
			upd(v * 2, l, mid, pos, k);
		else
			upd(v * 2 + 1, mid + 1, r, pos, k);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
	ll sum(ll v, ll l, ll r, ll x, ll y)
	{
		if (x > y || x > r || y < l)
			return 0;
		if (x <= l && r <= y)
			return tree[v];
		ll mid = (l + r) / 2;
		return sum(v * 2, l, mid, x, y) + sum(v * 2 + 1, mid + 1, r, x, y);
	}
};