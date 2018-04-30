/*
Floyd-Warshall O(N^3)
*/
ll dist[N+10][N+10];
struct edge{
	ll x,y,z;
	edge(ll x, ll y, ll z):x(x),y(y),z(z){}
}e[M+10];
void floydWarshall()
{
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			dist[i][j]=INF;
	for(ll i=1;i<=n;i++)
		dist[i][i]=0;
	for(ll i=1;i<=m;i++)
		dist[e[i].x][e[i].y]=e[i].z;
	for(ll k=1;k<=n;k++)
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}