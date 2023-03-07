/*
Дерево отрезков сверху вниз
- a[x] += y
- sum(l, r)
*/
template <typename Type>
struct segment_tree
{
private:
	int n;
	vector<Type> tree;
	void build_tree(int v, int l, int r, Type *a)
	{
		if (l == r)
		{
			tree[v] = a[l];
			return;
		}
		int mid = (l + r) / 2;
		build_tree(v * 2, l, mid, a);
		build_tree(v * 2 + 1, mid + 1, r, a);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
	void upd_tree(int v, int l, int r, int pos, Type k)
	{
		if (l == r)
		{
			tree[v] += k;
			return;
		}
		int mid = (l + r) / 2;
		if (pos <= mid)
			upd_tree(v * 2, l, mid, pos, k);
		else
			upd_tree(v * 2 + 1, mid + 1, r, pos, k);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
	Type get_sum(int v, int l, int r, int x, int y)
	{
		if (x > y || x > r || y < l)
			return 0;
		if (x <= l && r <= y)
			return tree[v];
		int mid = (l + r) / 2;
		return get_sum(v * 2, l, mid, x, y) + get_sum(v * 2 + 1, mid + 1, r, x, y);
	}

public:
	void build(int len, Type *a)
	{
		n = len;
		tree.resize(4 * n);
		build_tree(1, 1, n, a);
	}
	void upd(int pos, Type k)
	{
		upd_tree(1, 1, n, pos, k);
	}
	Type sum(int l, int r)
	{
		return get_sum(1, 1, n, l, r);
	}
};