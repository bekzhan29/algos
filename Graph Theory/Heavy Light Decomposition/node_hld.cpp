template <typename Type>
struct hld
{
	// https://github.com/bekzhan29/algos
private:
	int n, sz;
	vector<int> pr, pos, h, c;
	// https://github.com/bekzhan29/algos/blob/master/Data%20Structures/Segment%20Tree/segment_tree1.cpp
	segment_tree<Type> tree;
	vector<vector<int>> v;
	void dfs(int x, int par=0)
	{
		pr[x] = par;
		c[x] = 1;
		if (par == 0)
			pr[x] = x;
		for (int to : v[x])
			if (to != par)
				dfs(to, x), c[x] += c[to];
	}
	void hld_build(int x, int par=0, int head=0)
	{
		if (!head)
			head = x;
		h[x] = head;
		pos[x] = ++sz;
		int mx = 0, u;
		for (int to : v[x])
		{
			if (to == par)
				continue;
			if (mx < c[to])
				mx = c[to], u = to;
		}
		if (mx > 0)
			hld_build(u, x, head);
		for (int to : v[x])
		{
			if (to == par || to == u)
				continue;
			hld_build(to, x);
		}
	}

public:
	void init(int n = 1)
	{
		this->n = n;
		sz = 0;
		pos.resize(n + 1);
		h.resize(n + 1);
		c.resize(n + 1);
		pr.resize(n + 1);
		v.resize(n + 1);
	}
	void add_edge(int x, int y)
	{
		v[x].push_back(y);
		v[y].push_back(x);
	}
	void build(Type *a=NULL)
	{
		dfs(1);
		hld_build(1);
		tree.build(n);
		if (a == NULL)
			return;
		for (int i = 1; i <= n; i++)
			tree.upd(pos[i], a[i]);
	}
	void upd(int x, Type k)
	{
		tree.upd(pos[x], k);
	}
	Type get(int x, int y)
	{
		Type ans = -INF;
		for(;h[x] != h[y]; y = pr[h[y]])
		{
			if (pos[h[x]] > pos[h[y]])
				swap(x, y);
			ans = max(ans, tree.get(pos[h[y]], pos[y]));
		}
		if(pos[x] > pos[y])
			swap(x, y);
		ans = max(ans, tree.get(pos[x], pos[y]));
		return ans;
	}
};