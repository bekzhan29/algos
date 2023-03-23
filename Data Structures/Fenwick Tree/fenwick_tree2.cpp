template <typename Type>
struct fenwick
{
private:
	int n;
	vector<Type> tree[2];
	void add2(int ty, int pos, Type x)
	{
		// https://github.com/bekzhan29/algos
		for (; pos <= n; pos = (pos | (pos + 1)))
			tree[ty][pos] += x;
	}
	Type sum2(int ty, int pos)
	{
		ll ans = 0;
		for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
			ans += tree[ty][pos];
		return ans;
	}

public:
	void add(int l, int r, Type x)
	{
		add2(0, l, x);
		add2(0, r + 1, -x);
		add2(1, l, (1 - l) * x);
		add2(1, r + 1, r * x);
	}
	Type sum(int l, int r)
	{
		return sum2(0, r) * r - sum2(0, l - 1) * (l - 1) + sum2(1, r) - sum2(1, l - 1);
	}
	void build(int n)
	{
		this->n = n;
		tree[0].resize(n + 1);
		tree[1].resize(n + 1);
		for (int i = 0; i <= n; i++)
			tree[0][i] = tree[1][i] = 0;
		for (int i = 1; i <= n; i++)
			add2(1, i, a[i]);
	}
}