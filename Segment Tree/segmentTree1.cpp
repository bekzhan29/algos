/*
Дерево отрезков сверху вниз
- a[x] += y
- sum(l, r)
*/
template <typename Type>
struct segment_tree
{
	ll n;
	vector<Type> tree;
	void build(ll v, ll l, ll r, Type *a)
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
	void upd(ll v, ll l, ll r, ll pos, Type k)
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
	Type sum(ll v, ll l, ll r, ll x, ll y)
	{
		if (x > y || x > r || y < l)
			return 0;
		if (x <= l && r <= y)
			return tree[v];
		ll mid = (l + r) / 2;
		return sum(v * 2, l, mid, x, y) + sum(v * 2 + 1, mid + 1, r, x, y);
	}
	void build(ll n, Type *a)
	{
		this->n = n;
		tree.resize(4 * n);
		build(1, 1, n, a);
	}
	void upd(ll pos, Type k)
	{
		upd(1, 1, n, pos, k);
	}
	Type sum(ll l, ll r)
	{
		return sum(1, 1, n, l, r);
	}
};