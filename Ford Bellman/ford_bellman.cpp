/*
https://github.com/bekzhan29/algos/

Алгоритм Форда-Беллмана O(NM)
*/
ll dist[N];
struct edge
{
	ll x, y, w;
	edge(ll x = 0, ll y = 0, ll w = 0) : x(x), y(y), w(w) {}
} e[N];
void ford_bellman(int st, int n, int m)
{
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[st] = 0;
	for (int i = 1; i <= n; i++)
	{
		bool optimized = false;
		for (int j = 1; j <= m; j++)
			if (dist[e.y] > dist[e.x] + e.w)
			{
				optimized = true;
				dist[e.y] = dist[e.x] + e.w;
				if (i == n)
					cout << "Negative weight cycle"
			}
		if (!optimized)
			break;
	}
}