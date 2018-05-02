/*
Наименьший общий предок
Поиск двоичным подьемом O(logN)
*/
ll pr[17][N+10],tin[N+10],tout[N+10],tim;
vector<ll>v[N+10];
void dfs(ll x, ll par)
{
	tin[x]=++tim;
	pr[0][x]=par;
	if(par==0)
		pr[0][x]=x;
	for(ll i=1;i<17;i++)
		pr[i][x]=pr[i-1][pr[i-1][x]];
	for(ll to:v[x])
		if(to!=par)
			dfs(to,x);
	tout[x]=tim;
}
ll lca(ll x, ll y)
{
	ll lca=x;
	for(ll i=16;i>=0;i--)
		if(tin[pr[i][lca]]>tin[y]||tout[y]>tout[pr[i][lca]])
			lca=pr[i][lca];
	if(tin[lca]>tin[y]||tout[y]>tout[lca])
		lca=pr[0][lca];
	return lca;
}
void init(ll root)
{
	dfs(root,0);
}