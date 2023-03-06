/*
Дерево отрезков сверху вниз
- upd(l, r) += k
- sum(l, r)
*/
template <typename Type>
struct segment_tree
{
	ll n;
	vector<Type> tree, z;
	void build(ll v, ll l, ll r, Type *a)
	{
		if (l == r)
		{
			tree[v] = a[l];
			z[v] = 0;
			return;
		}
		ll mid = (l + r) / 2;
		build(v * 2, l, mid, a);
		build(v * 2 + 1, mid + 1, r, a);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
		z[v] = 0;
	}
	void push(ll v, ll l, ll r, ll mid)
	{
		if (z[v] == 0)
			return;
		z[v * 2] += z[v];
		z[v * 2 + 1] += z[v];
		tree[v * 2] += z[v] * (mid - l + 1);
		tree[v * 2 + 1] += z[v] * (r - mid);
		z[v] = 0;
	}
	void upd(ll v, ll l, ll r, ll x, ll y, Type k)
	{
		if (x > y || x > r || y < l)
			return;
		if (x <= l && r <= y)
		{
			tree[v] += (r - l + 1) * k;
			z[v] += k;
			return;
		}
		ll mid = (l + r) / 2;
		push(v, l, r, mid);
		upd(v * 2, l, mid, x, y, k);
		upd(v * 2 + 1, mid + 1, r, x, y, k);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
	Type sum(ll v, ll l, ll r, ll x, ll y)
	{
		if (x > y || x > r || y < l)
			return 0;
		if (x <= l && r <= y)
			return tree[v];
		ll mid = (l + r) / 2;
		push(v, l, r, mid);
		return sum(v * 2, l, mid, x, y) + sum(v * 2 + 1, mid + 1, r, x, y);
	}
	void build(ll n, Type *a)
	{
		this->n = n;
		tree.resize(4 * n);
		z.resize(4 * n);
		build(1, 1, n, a);
	}
	void upd(ll l, ll r, Type k)
	{
		upd(1, 1, n, l, r, k);
	}
	Type sum(ll l, ll r)
	{
		return sum(1, 1, n, l, r);
	}
};