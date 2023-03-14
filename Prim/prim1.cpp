/*
Алгоритм Прима O(MlogN)
*/
ll dist[N], w[N], pr[N];
struct edge
{
	ll x, y, w;
	edge(ll x = 0, ll y = 0, ll w = 0) : x(x), y(y), w(w) {}
};
vector<edge> v[N];
void prim(ll n)
{
	// https://github.com/bekzhan29/algos
	priority_queue<pair<ll, ll>> s;
	for (ll i = 1; i <= n; i++)
		dist[i] = INF, w[i] = 0;
	dist[1] = 0;
	s.push({0, 1});
	for (; !s.empty();)
	{
		ll x = s.top().se;
		s.pop();
		if (w[x])
			continue;
		w[x] = 1;
		for (edge e : v[x])
			if (!w[e.y] && e.w < dist[e.y])
				dist[e.y] = e.w, pr[e.y] = e.x, s.push({-dist[e.y], e.y});
	}
}