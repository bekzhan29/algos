/*
Алгоритм Форда-Беллмана O(NM)
*/
ll dist[N];
struct edge
{
	ll x, y, w;
	edge(ll x = 0, ll y = 0, ll w = 0) : x(x), y(y), w(w) {}
} e[N];
void fordBellman(ll st, ll n, ll m)
{
	for (ll i = 1; i <= n; i++)
		dist[i] = INF;
	dist[st] = 0;
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= m; j++)
			if (dist[e.y] > dist[e.x] + e.w)
			{
				dist[e.y] = dist[e.x] + e.w;
				if (i == n)
					cout << "Negative weight cycle"
			}
}