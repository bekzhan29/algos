template <typename Type>
struct segment_tree
{
	// https://github.com/bekzhan29/algos
private:
	int n;
	vector<Type> tree;
	void build_tree(int v, int vl, int vr, Type *a)
	{
		if (vl == vr)
		{
			if (a == NULL)
				tree[v] = 0;
			else
				tree[v] = a[vl];
			return;
		}
		int mid = (vl + vr) / 2;
		build_tree(v * 2, vl, mid, a);
		build_tree(v * 2 + 1, mid + 1, vr, a);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
	void upd_tree(int v, int vl, int vr, int pos, Type k)
	{
		if (vl == vr)
		{
			tree[v] += k;
			return;
		}
		int mid = (vl + vr) / 2;
		if (pos <= mid)
			upd_tree(v * 2, vl, mid, pos, k);
		else
			upd_tree(v * 2 + 1, mid + 1, vr, pos, k);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
	Type get_tree(int v, int vl, int vr, int l, int r)
	{
		if (l > r || l > vr || r < vl)
			return 0;
		if (l <= vl && vr <= r)
			return tree[v];
		int mid = (vl + vr) / 2;
		return get_tree(v * 2, vl, mid, l, r) + get_tree(v * 2 + 1, mid + 1, vr, l, r);
	}

public:
	void build(int len, Type *a=NULL)
	{
		n = len;
		tree.resize(4 * n);
		build_tree(1, 1, n, a);
	}
	void upd(int pos, Type k)
	{
		upd_tree(1, 1, n, pos, k);
	}
	Type get(int l, int r)
	{
		return get_tree(1, 1, n, l, r);
	}
};