/*
https://github.com/bekzhan29/algos/

Алгоритм Дейкстры O(M+N^2)
*/
ll dist[N], w[N];
struct edge
{
	ll x, y, w;
	edge(ll x = 0, ll y = 0, ll w = 0) : x(x), y(y), w(w) {}
};
vector<edge> v[N];
void dijkstra(ll st, ll n)
{
	for (ll i = 1; i <= n; i++)
		dist[i] = INF, w[i] = 0;
	dist[st] = 0;
	for (;;)
	{
		ll x = 0;
		for (ll i = 1; i <= n; i++)
			if (w[i] == 0 && (x == 0 || dist[i] < dist[x]))
				x = i;
		if (x == 0)
			break;
		w[x] = 1;
		for (edge e : v[x])
			if (dist[e.x] + e.w < dist[e.y])
				dist[e.y] = dist[e.x] + e.w;
	}
}