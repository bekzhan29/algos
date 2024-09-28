template <typename Type>
struct hld
{
	// https://github.com/bekzhan29/algos
private:
	int n, cnt, sz;
	vector<int> pr, pos, head, ind, l, r, c;
	// https://github.com/bekzhan29/algos/blob/master/Data%20Structures/Segment%20Tree/segment_tree1.cpp
	segment_tree<Type> tree;
	vector<vector<int>> v;
	void dfs(int x, int par)
	{
		pr[x] = par;
		c[x] = 1;
		if (par == 0)
			pr[x] = x;
		for (int to : v[x])
			if (to != par)
				dfs(to, x), c[x] += c[to];
	}
	void hld_build(int x, int par)
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
			hld_build(u, x);
		for (int to : v[x])
		{
			if (to == par || to == u)
				continue;
			cnt++;
			hld_build(to, x);
		}
	}

public:
	void init(int n = 1)
	{
		this->n = n;
		pos.resize(n + 1);
		head.resize(n + 1);
		ind.resize(n + 1);
		l.resize(n + 1);
		r.resize(n + 1);
		c.resize(n + 1);
		pr.resize(n + 1);
		v.resize(n + 1);
		cnt = 1;
	}
	void add_edge(int x, int y)
	{
		v[x].push_back(y);
		v[y].push_back(x);
	}
	void build()
	{
		dfs(1, 0);
		hld_build(1, 0);
		tree.build(n);
	}
	void upd(int x, Type k)
	{
		tree.upd(pos[x], k);
	}
	Type get(int x, int y)
	{
		Type ans = -INF;
		for(;ind[x] != ind[y]; y = pr[head[ind[y]]])
		{
			if (l[ind[x]] > l[ind[y]])
				swap(x, y);
			ans = max(ans, tree.get(l[ind[y]], pos[y]));
		}
		if(pos[x] > pos[y])
			swap(x, y);
		ans = max(ans, tree.get(pos[x], pos[y]));
		return ans;
	}
};