struct dsu_tree
{
	int cnt, timer, lg, phase = 0;
	vector<int> p, r, t, par;
	vector<vector<int>> pr;
	void init(int n)
	{
		assert(phase == 0);
		phase++;
		cnt = n;
		p.resize(2 * n);
		r.resize(2 * n);
		t.resize(2 * n);
		par.resize(2 * n);
		for (int i = 1; i < 2 * n; i++)
			p[i] = par[i] = i, r[i] = 1, t[i] = 0;
	}
	int fin(int a)
	{
		assert(phase == 1);
		if (a == p[a])
			return a;
		return p[a] = fin(p[a]);
	}
	bool uni(int a, int b)
	{
		assert(phase == 1);
		a = fin(a), b = fin(b);
		timer++;
		if (a == b)
			return false;
		cnt++;
		par[a] = par[b] = p[a] = p[b] = cnt;
		r[cnt] = r[a] + r[b];
		t[cnt] = timer;
		return true;
	}
	void init2()
	{
		assert(phase == 1);
		phase++;
		lg = 0;
		while ((1 << lg) <= cnt)
			lg++;
		pr.resize(lg);
		for (int i = 0; i < lg; i++)
			pr[i].resize(cnt + 1);
		for (int i = 0; i < lg; i++)
			pr[i][0] = 0;
		for (int i = 1; i <= cnt; i++)
			pr[0][i] = par[i];
		for (int j = 1; j < lg; j++)
			for (int i = 1; i <= cnt; i++)
				pr[j][i] = pr[j - 1][pr[j - 1][i]];
	}
	int fin(int ti, int a)
	{
		assert(phase == 2);
		for (int i = lg - 1; i >= 0; i--)
			if (t[pr[i][a]] <= ti)
				a = pr[i][a];
		return a;
	}
	int sz(int a)
	{
		assert(phase == 2);
		return r[a];
	}
};