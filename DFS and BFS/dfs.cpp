struct graph
{
	// https://github.com/bekzhan29/algos
	int n;
	vector<vector<int>> g;
	vector<bool> used;
	vector<int> d;
	graph(int n)
	{
		this->n = n;
		g = vector<vector<int>>(n, vector<int>(0));
		used = vector<bool>(n, false);
		d = vector<int>(n, -1);
	}
	void add_edge(int v, int u, bool directional)
	{
		g[v].push_back(u);
		if (!directional)
			g[u].push_back(v);
	}
	void dfs(int v, int p = -1)
	{
		used[v] = true;
		for (int to : g[v])
		{
			if (!used[to])
				dfs(to, v);
		}
	}
};