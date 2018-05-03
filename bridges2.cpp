/*
Поиск мостов в связном графе O(N+M)
Граф может содержать кратные рёбра

*/
struct edge{
	ll x,y,ind;
	edge(ll x=0, ll y=0, ll ind=0):x(x),y(y),ind(ind){}
}br[N+10];
ll cnt,w[N+10],dep[N+10],up[N+10];
vector<edge>v[N+10];
void dfs(ll x, edge last, ll depth)
{
	dep[x]=up[x]=depth;
	w[x]=1;
	for(edge e:v[x])
	{
		if(e.ind==last.ind)
			continue;
		ll to=e.y;
		if(!w[to])
		{
			dfs(to,e,depth+1);
			up[x]=min(up[x],up[to]);
			if(up[to]>dep[x])
				br[++cnt]=e;
		}
		else
			up[x]=min(up[x],dep[to]);
	}
}