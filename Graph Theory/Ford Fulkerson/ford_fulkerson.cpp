struct max_flow
{
	int n;
	vector<vector<int>> f, c;
	vector<int> w;
	max_flow(int n)
	{
		this->n = n;
		f.resize(n + 1);
		c.resize(n + 1);
		w.resize(n + 1);
		for (int i = 1; i <= n; i++)
		{
			f[i].resize(n + 1);
			c[i].resize(n + 1);
		}
	}
	int dfs(int x, int t, int flow)
	{
		if (x == t)
			return flow;
		w[x] = 1;
		for (int to = 1; to <= n; to++)
			if (!w[to] && c[x][to] - f[x][to] > 0)
			{
				flow = dfs(to, t, min(flow, c[x][to] - f[x][to]));
				f[x][to] += flow;
				f[to][x] -= flow;
				if (flow)
					return flow;
			}
		return 0;
	}
	int flow(int s, int t)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = 0;
		for (int i = 1; i <= n; i++)
			w[i] = 1;
		dfs(s, t, INF);
		for (int i = 1; i <= n; i++)
			if (f[s][i] > 0)
				ans += f[s][i];
		return ans;
	}
};