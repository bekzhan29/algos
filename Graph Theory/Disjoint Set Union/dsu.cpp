struct dsu
{
	vector<int> p, r;
	int fin(int a)
	{
		// https://github.com/bekzhan29/algos
		if (a == p[a])
			return a;
		return p[a] = fin(p[a]);
	}
	bool union_sets(int a, int b)
	{
		a = fin(a), b = fin(b);
		if (a == b)
			return 0;
		if (r[a] > r[b])
			r[a] += r[b], p[b] = a;
		else
			r[b] += r[a], p[a] = b;
		return 1;
	}
	void init_dsu(int n)
	{
		p.resize(n + 1);
		r.resize(n + 1);
		for (int i = 1; i <= n; i++)
			p[i] = i, r[i] = 1;
	}
};