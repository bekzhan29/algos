template <typename Type>
struct segment_tree
{
	// https://github.com/bekzhan29/algos
private:
	int n;
	vector<Type> tree, z;
	void build_tree(int v, int vl, int vr, Type *a)
	{
		if (vl == vr)
		{
			tree[v] = a[vl];
			z[v] = 0;
			return;
		}
		int mid = (vl + vr) / 2;
		build_tree(v * 2, vl, mid, a);
		build_tree(v * 2 + 1, mid + 1, vr, a);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
		z[v] = 0;
	}
	void push(int v, int vl, int vr, int mid)
	{
		if (z[v] == 0)
			return;
		z[v * 2] += z[v];
		z[v * 2 + 1] += z[v];
		tree[v * 2] += z[v] * (mid - vl + 1);
		tree[v * 2 + 1] += z[v] * (vr - mid);
		z[v] = 0;
	}
	void upd_tree(int v, int vl, int vr, int l, int r, Type k)
	{
		if (l > r || l > vr || r < vl)
			return;
		if (l <= vl && vr <= r)
		{
			tree[v] += (vr - vl + 1) * k;
			z[v] += k;
			return;
		}
		int mid = (vl + vr) / 2;
		push(v, vl, vr, mid);
		upd_tree(v * 2, vl, mid, l, r, k);
		upd_tree(v * 2 + 1, mid + 1, vr, l, r, k);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
	Type get_sum(int v, int vl, int vr, int l, int r)
	{
		if (l > r || l > vr || r < vl)
			return 0;
		if (l <= vl && vr <= r)
			return tree[v];
		int mid = (vl + vr) / 2;
		push(v, vl, vr, mid);
		return get_sum(v * 2, vl, mid, l, r) + get_sum(v * 2 + 1, mid + 1, vr, l, r);
	}

public:
	void build(int n, Type *a)
	{
		this->n = n;
		tree.resize(4 * n);
		z.resize(4 * n);
		build_tree(1, 1, n, a);
	}
	void upd(int l, int r, Type k)
	{
		upd_tree(1, 1, n, l, r, k);
	}
	Type sum(int l, int r)
	{
		return get_sum(1, 1, n, l, r);
	}
};