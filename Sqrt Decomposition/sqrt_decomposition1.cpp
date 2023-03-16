template <typename Type>
struct sqrt_dec
{
	// https://github.com/bekzhan29/algos
	int len;
	vector<Type> a, bl;
	void build(int n, Type *ar)
	{
		len = sqrt(n);
		bl.resize(n / len + 1);
		a.push_back(0);
		for (int i = 1; i <= n; i++)
		{
			a.push_back(ar[i]);
			bl[i / len] += ar[i];
		}
	}
	void upd(int pos, Type k)
	{
		a[pos] += k;
		bl[pos / len] += k;
	}
	Type sum(int l, int r)
	{
		Type ans = 0;
		int cl = l / len, cr = r / len;
		if (cl == cr)
		{
			for (int i = l; i <= r; i++)
				ans += a[i];
			return ans;
		}
		for (int i = l; i < (cl + 1) * len; i++)
			ans += a[i];
		for (int i = cl + 1; i < cr; i++)
			ans += bl[i];
		for (int i = cr * len; i <= r; i++)
			ans += a[i];
		return ans;
	}
};