/*
Поиск точек сочленения в связном графе O(N+M)
Граф может содержать кратные рёбра
*/
ll cnt,w[N+10],dep[N+10],up[N+10],cut[N+10];
vector<ll>v[N+10];
void dfs(ll x, ll pr, ll depth)
{
	dep[x]=up[x]=depth;
	w[x]=1;
	ll ch=0,go=0;
	for(ll to:v[x])
	{
		if(to==pr)
			continue;
		if(!w[to])
		{
			go++;
			dfs(to,x,depth+1);
			up[x]=min(up[x],up[to]);
			if(up[to]>=dep[x])
				ch=1;
		}
		else
			up[x]=min(up[x],dep[to]);
	}
	if(pr==0)
		ch=go>1;
	if(ch)
		cut[++cnt]=x;
}