template <typename Type>
struct segment_tree
{
	// https://github.com/bekzhan29/algos
private:
	int n1;
	vector<Type> tree;

public:
	void build(int n, Type *a)
	{
		tree.resize(4 * n);
		n1 = 1;
		while (n1 < n)
			n1 *= 2;
		n1--;
		for (int i = 1; i <= n; i++)
			tree[i + n1] = a[i];
		for (int i = n1; i >= 1; i--)
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
	void upd(int pos, Type k)
	{
		pos += n1;
		tree[pos] += k;
		pos /= 2;
		for (; pos; pos /= 2)
			tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
	}
	Type sum(int l, int r)
	{
		l += n1;
		r += n1;
		Type ans = 0;
		while (l <= r)
		{
			if (l & 1)
				ans += tree[l], l++;
			if (!(r & 1))
				ans += tree[r], r--;
			l /= 2;
			r /= 2;
		}
		return ans;
	}
};