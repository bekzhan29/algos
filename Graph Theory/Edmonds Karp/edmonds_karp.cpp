struct max_flow
{
	int n;
	vector<vector<int>> f, c;
	vector<int> w, d, p, g;
	max_flow(int n)
	{
		this->n = n;
		f.resize(n + 1);
		c.resize(n + 1);
		w.resize(n + 1);
		d.resize(n + 1);
		p.resize(n + 1);
		g.resize(n + 1);
		for (int i = 1; i <= n; i++)
		{
			f[i].resize(n + 1);
			c[i].resize(n + 1);
			for (int j = 1; j <= n; j++)
				f[i][j] = c[i][j] = 0;
		}
	}
	int bfs(int s, int t)
	{
		for (int i = 1; i <= n; i++)
			d[i] = n + 1, p[i] = g[i] = 0;
		d[s] = 0;
		g[s] = INF;
		queue<int> q;
		q.push(s);
		for (; !q.empty();)
		{
			int x = q.front();
			q.pop();
			for (int to = 1; to <= n; to++)
				if (d[to] > d[x] + 1 && c[x][to] > f[x][to])
				{
					d[to] = d[x] + 1;
					p[to] = x;
					g[to] = min(g[x], c[x][to] - f[x][to]);
					q.push(to);
				}
		}
		int delta = g[t];
		for (int x = t; p[x]; x = p[x])
		{
			f[p[x]][x] += delta;
			f[x][p[x]] -= delta;
		}
		return delta;
	}
	int flow(int s, int t)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = 0;
		for (;;)
		{
			for (int i = 1; i <= n; i++)
				w[i] = 0;
			int flow = bfs(s, t);
			ans += flow;
			if (!flow)
				break;
		}
		return ans;
	}
};