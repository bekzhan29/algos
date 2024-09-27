struct dsu
{
	vector<int> p, r;
	int find_root(int a)
	{
		// https://github.com/bekzhan29/algos
		if (a == p[a])
			return a;
		return p[a] = find_root(p[a]);
	}
	bool union_sets(int a, int b)
	{
		a = find_root(a), b = find_root(b);
		if (a == b)
			return 0;
		if (r[a] > r[b])
			r[a] += r[b], p[b] = a;
		else
			r[b] += r[a], p[a] = b;
		return 1;
	}
	void init(int n)
	{
		p.resize(n + 1);
		r.resize(n + 1);
		for (int i = 1; i <= n; i++)
			p[i] = i, r[i] = 1;
	}
};
