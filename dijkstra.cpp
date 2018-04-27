/*
Dijkstra's algorithm O(MlogN)
*/
ll dist[N+10],w[N+10];
struct edge{
	ll x,y,z;
	edge(ll x, ll y, ll z):x(x),y(y),z(z){}
};
vector<edge>v[N+10];
void dijkstra()
{
	priority_queue<pair<ll,ll> >s;
	for(ll i=1;i<=n;i++)
		dist[i]=INF;
	dist[st]=0;
	s.push({0,st});
	for(;!s.empty();)
	{
		ll x=s.top().se;
		s.pop();
		if(w[x])
			continue;
		w[x]=1;
		for(edge e:v[x])
			if(dist[e.x]+e.z<dist[e.y])
				dist[e.y]=dist[e.x]+e.z,s.push({-dist[e.y],e.y});
	}
}