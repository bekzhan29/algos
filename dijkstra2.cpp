/*
Dijkstra's algorithm O(M+N^2)
*/
ll dist[N+10],w[N+10];
struct edge{
	ll x,y,z;
	edge(ll x, ll y, ll z):x(x),y(y),z(z){}
};
vector<edge>v[N+10];
void dijkstra()
{
	for(ll i=1;i<=n;i++)
		dist[i]=INF,w[i]=0;
	dist[st]=0;
	for(;;)
	{
		ll x=0;
		for(ll i=1;i<=n;i++)
			if(w[i]==0&&(x==0||dist[i]<dist[x]))
				x=i;
		if(x==0)
			break;
		w[x]=1;
		for(edge e:v[x])
			if(dist[e.x]+e.z<dist[e.y])
				dist[e.y]=dist[e.x]+e.z;
	}
}