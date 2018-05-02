/*
Heavy-Light Decomposition
- a[x] += y O(logN)
- max(x,y) O(log^2(N))
*/
ll pr[17][N+10],tin[N+10],tout[N+10],tim,tree[3*N+10],a[N+10],pos[N+10],head[N+10],ind[N+10],l[N+10],r[N+10],c[N+10],cnt,sz;
vector<ll>v[N+10];
void dfs(ll x, ll par)
{
	tin[x]=++tim;
	pr[0][x]=par;
	c[x]=1;
	if(par==0)
		pr[0][x]=x;
	for(ll i=1;i<17;i++)
		pr[i][x]=pr[i-1][pr[i-1][x]];
	for(ll to:v[x])
		if(to!=par)
			dfs(to,x),c[x]+=c[to];
	tout[x]=tim;
}
ll findLCA(ll x, ll y)
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
void build(ll v, ll l, ll r)
{
	if(l==r)
	{
		tree[v]=a[l];
		return;
	}
	ll mid=(l+r)/2;
	build(v*2,l,mid);
	build(v*2+1,mid+1,r);
	tree[v]=max(tree[v*2],tree[v*2+1]);
}
void upd(ll v, ll l, ll r, ll pos, ll k)
{
	if(l==r)
	{
		tree[v]+=k;
		return;
	}
	ll mid=(l+r)/2;
	if(pos<=mid)
		upd(v*2,l,mid,pos,k);
	else
		upd(v*2+1,mid+1,r,pos,k);
	tree[v]=max(tree[v*2],tree[v*2+1]);
}
ll getMax(ll v, ll l, ll r, ll x, ll y)
{
	if(x>y||x>r||y<l)
		return 0;
	if(x<=l&&r<=y)
		return tree[v];
	ll mid=(l+r)/2;
	return max(getMax(v*2,l,mid,x,y),getMax(v*2+1,mid+1,r,x,y));
}
void hld(ll x, ll par)
{
	pos[x]=++sz;
	if(head[cnt]==0)
		head[cnt]=x,l[cnt]=pos[x];
	ind[x]=cnt;
	r[cnt]=pos[x];
	ll mx=0,u;
	for(ll to:v[x])
	{
		if(to==par)
			continue;
		if(mx<c[to])
			mx=c[to],u=to;
	}
	if(mx>0)
		hld(u,x);
	for(ll to:v[x])
	{
		if(to==par||to==u)
			continue;
		cnt++;
		hld(to,x);
	}
}
ll hldMax(ll x, ll y)
{
	ll ans=-INF;
	while(ind[y]!=ind[x])
	{
		ans=max(ans,getMax(1,1,n,l[ind[y]],pos[y]));
		y=pr[0][head[ind[y]]];
	}
	ans=max(ans,getMax(1,1,n,pos[x],pos[y]));
	return ans;
}