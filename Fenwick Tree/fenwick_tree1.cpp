/*
Дерево Фенвика O(NlogN)
- Сумма на отрезке O(logN)
- a[x] += y O(logN)
*/
template <typename Type>
struct fenwick
{
private:
	int n;
	Type tree[N];
	Type sum(int pos)
	{
		int ans = 0;
		for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
			ans += tree[pos];
		return ans;
	}

public:
	void build(int n, Type *a)
	{
		this->n = n;
		for (int i = 0; i <= n; i++)
			tree[i] = 0;
		for (int i = 1; i <= n; i++)
			add(i, a[i]);
	}
	void add(int pos, Type x)
	{
		for (; pos <= n; pos = (pos | (pos + 1)))
			tree[pos] += x;
	}
	Type sum(int l, int r)
	{
		return sum(r) - sum(l - 1);
	}
};