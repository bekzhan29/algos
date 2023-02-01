/*
Bellman-Ford's algorithm O(NM)
*/
ll dist[N + 10];
struct edge
{
	ll x, y, z;
	edge(ll x, ll y, ll z) : x(x), y(y), z(z) {}
} e[N + 10];
void fordBellman()
{
	for (ll i = 1; i <= n; i++)
		dist[i] = INF;
	dist[st] = 0;
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= m; j++)
			if (dist[e.y] > dist[e.x] + e.z)
			{
				dist[e.y] = dist[e.x] + e.z;
				if (i == n)
					cout << "Negative weight cycle"
			}
}
