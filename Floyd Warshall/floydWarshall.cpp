/*
Floyd-Warshall O(N^3)
*/
ll x[N * N], y[N * N], z[N * N], dist[N][N];
void floydWarshall()
{
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= n; j++)
			dist[i][j] = INF;
	for (ll i = 1; i <= n; i++)
		dist[i][i] = 0;
	for (ll i = 1; i <= m; i++)
		dist[x[i]][y[i]] = z[i],
		dist[y[i]][x[i]] = z[i];
	for (ll k = 1; k <= n; k++)
		for (ll i = 1; i <= n; i++)
			for (ll j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}