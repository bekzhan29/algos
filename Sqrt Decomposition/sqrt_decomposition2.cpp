template <typename Type>
struct sqrt_dec
{
	// https://github.com/bekzhan29/algos
	int len;
	vector<Type> a, bl, zl;
	void build(int n, Type *ar)
	{
		len = sqrt(n);
		bl.resize(n / len + 1);
		zl.resize(n / len + 1);
		a.push_back(0);
		for (int i = 1; i <= n; i++)
		{
			a.push_back(ar[i]);
			bl[i / len] += ar[i];
		}
	}
	void push(int pos)
	{
		if (zl[pos] == 0)
			return;
		for (int i = pos * len; i < (pos + 1) * len; i++)
			a[i] += zl[pos];
		zl[pos] = 0;
	}
	void upd(int l, int r, Type k)
	{
		int cl = l / len, cr = r / len;
		if (cl == cr)
		{
			push(cl);
			for (int i = l; i <= r; i++)
				a[i] += k, bl[cl] += k;
			return;
		}
		push(cl);
		push(cr);
		for (int i = l; i < (cl + 1) * len; i++)
			a[i] += k, bl[cl] += k;
		for (int i = cl + 1; i < cr; i++)
			zl[i] += k, bl[i] += len * k;
		for (int i = cr * len; i <= r; i++)
			a[i] += k, bl[cr] += k;
	}
	Type sum(int l, int r)
	{
		Type ans = 0;
		int cl = l / len, cr = r / len;
		if (cl == cr)
		{
			push(cl);
			for (int i = l; i <= r; i++)
				ans += a[i];
			return ans;
		}
		push(cl);
		push(cr);
		for (int i = l; i < (cl + 1) * len; i++)
			ans += a[i];
		for (int i = cl + 1; i < cr; i++)
			ans += bl[i];
		for (int i = cr * len; i <= r; i++)
			ans += a[i];
		return ans;
	}
};