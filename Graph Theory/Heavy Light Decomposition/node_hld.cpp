struct hld
{
	// https://github.com/bekzhan29/algos
	int k, cnt, sz, tim;
	vector<int> tin, tout, tree, a, pos, head, ind, l, r, c;
	vector<vector<int>> v, pr;
	void dfs(int x, int par)
	{
		tin[x] = ++tim;
		pr[0][x] = par;
		c[x] = 1;
		if (par == 0)
			pr[0][x] = x;
		for (int i = 1; i < k; i++)
			pr[i][x] = pr[i - 1][pr[i - 1][x]];
		for (int to : v[x])
			if (to != par)
				dfs(to, x), c[x] += c[to];
		tout[x] = tim;
	}
	void hld(int x, int par)
	{
		pos[x] = ++sz;
		if (head[cnt] == 0)
			head[cnt] = x, l[cnt] = pos[x];
		ind[x] = cnt;
		r[cnt] = pos[x];
		int mx = 0, u;
		for (int to : v[x])
		{
			if (to == par)
				continue;
			if (mx < c[to])
				mx = c[to], u = to;
		}
		if (mx > 0)
			hld(u, x);
		for (int to : v[x])
		{
			if (to == par || to == u)
				continue;
			cnt++;
			hld(to, x);
		}
	}
	int find_lca(int x, int y)
	{
		int lca = x;
		for (int i = k - 1; i >= 0; i--)
			if (tin[pr[i][lca]] > tin[y] || tout[y] > tout[pr[i][lca]])
				lca = pr[i][lca];
		if (tin[lca] > tin[y] || tout[y] > tout[lca])
			lca = pr[0][lca];
		return lca;
	}
	void init(int n = 1, int root = 1)
	{
		tin.resize(n + 1);
		tout.resize(n + 1);
		tree.resize(4 * n);
		a.resize(n + 1);
		pos.resize(n + 1);
		head.resize(n + 1);
		ind.resize(n + 1);
		l.resize(n + 1);
		r.resize(n + 1);
		c.resize(n + 1);
		k = 0;
		while((1LL<<k)<n)
			k++;
		pr.resize(k);
		for (int i = 0; i < k; i++)
			pr[i].resize(n + 1);
		v.resize(n + 1);
		cnt = 1;
		dfs(root, 0);
		hld(root, 0);
	}
	void build(int v, int l, int r)
	{
		if (l == r)
		{
			tree[v] = a[l];
			return;
		}
		int mid = (l + r) / 2;
		build(v * 2, l, mid);
		build(v * 2 + 1, mid + 1, r);
		tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
	}
	void tree_upd(int v, int l, int r, int pos, int k)
	{
		if (l == r)
		{
			tree[v] += k;
			return;
		}
		int mid = (l + r) / 2;
		if (pos <= mid)
			tree_upd(v * 2, l, mid, pos, k);
		else
			tree_upd(v * 2 + 1, mid + 1, r, pos, k);
		tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
	}
	int tree_max(int v, int l, int r, int x, int y)
	{
		if (x > y || x > r || y < l)
			return -INF;
		if (x <= l && r <= y)
			return tree[v];
		int mid = (l + r) / 2;
		return max(tree_max(v * 2, l, mid, x, y), tree_max(v * 2 + 1, mid + 1, r, x, y));
	}
	int hld_max(int x, int y)
	{
		int ans = -INF;
		while (ind[y] != ind[x])
		{
			ans = max(ans, tree_max(1, 1, n, l[ind[y]], pos[y]));
			y = pr[0][head[ind[y]]];
		}
		ans = max(ans, tree_max(1, 1, n, pos[x], pos[y]));
		return ans;
	}
	void add_edge(int x, int y)
	{
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int find_max(int x, int y)
	{
		int lca = find_lca(x, y);
		return max(hld_max(lca, x), hld_max(lca, y));
	}
};