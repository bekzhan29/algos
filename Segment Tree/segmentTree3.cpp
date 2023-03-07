/*
Дерево отрезков сверху вниз
- upd(l, r) += k
- sum(l, r)
*/
template <typename Type>
struct segment_tree
{
private:
	ll n1;
	vector<Type> tree;

public:
	void build(ll n, Type *a)
	{
		tree.resize(4 * n);
		n1 = 1;
		while (n1 < n)
			n1 *= 2;
		n1--;
		for (ll i = 1; i <= n; i++)
			tree[i + n1] = a[i];
		for (ll i = n1; i >= 1; i--)
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
	void upd(ll pos, Type k)
	{
		pos += n1;
		tree[pos] += k;
		pos /= 2;
		for (; pos; pos /= 2)
			tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
	}
	Type sum(ll l, ll r)
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