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
	void bfs(int start)
	{
		queue<int> q;
		q.push(start);
		d[start] = 0;
		while (!q.empty())
		{
			int v = q.front();
			q.pop();
			for (int to : g[v])
			{
				if (d[to] == -1)
				{
					d[to] = d[v] + 1;
					q.push(to);
				}
			}
		}
	}
};