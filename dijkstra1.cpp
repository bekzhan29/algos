/*
Алгоритм Дейкстры O(MlogN)
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
	priority_queue<pair<ll, ll>> s;
	for (ll i = 1; i <= n; i++)
		dist[i] = INF, w[i] = 0;
	dist[st] = 0;
	s.push({0, st});
	for (; !s.empty();)
	{
		ll x = s.top().se;
		s.pop();
		if (w[x])
			continue;
		w[x] = 1;
		for (edge e : v[x])
			if (dist[e.x] + e.w < dist[e.y])
				dist[e.y] = dist[e.x] + e.w, s.push({-dist[e.y], e.y});
	}
}