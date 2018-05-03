/*
Наименьший общий предок
Поиск деревом отрезков O(logN)
*/
ll sz,pos[N+10],ord[2*N+10],dep[2*N+10],tree[6*N+10],ptree[6*N+10];
vector<ll>v[N+10];
void dfs(ll x, ll par, ll depth)
{
	ord[++sz]=x;
	dep[sz]=depth;
	pos[x]=sz;
	for(ll to:v[x])
		if(to!=par)
		{
			dfs(to,x,depth+1);
			ord[++sz]=x;
			dep[sz]=depth;
		}
}
void init(ll root)
{
	dfs(root,0,1);
}
void build(ll v, ll l, ll r)
{
	if(l==r)
	{
		tree[v]=dep[l];
		ptree[v]=l;
		return;
	}
	ll mid=(l+r)/2;
	build(v*2,l,mid);
	build(v*2+1,mid+1,r);
	tree[v]=min(tree[v*2],tree[v*2+1]);
	if(tree[v*2]<tree[v*2+1])
		ptree[v]=ptree[v*2];
	else
		ptree[v]=ptree[v*2+1];
}
ll getMin(ll v, ll l, ll r, ll x, ll y, ll &pos)
{
	if(x>y||x>r||y<l)
		return INF;
	if(x<=l&&r<=y)
	{
		pos=ptree[v];
		return tree[v];
	}
	ll mid=(l+r)/2,p1,p2;
	ll left=getMin(v*2,l,mid,x,y,p1),right=getMin(v*2+1,mid+1,r,x,y,p2);
	if(left<right)
	{
		pos=p1;
		return left;
	}
	pos=p2;
	return right;
}
ll findLCA(ll x, ll y)
{
	if(pos[x]>pos[y])
		swap(x,y);
	ll p;
	ll ans=getMin(1,1,sz,pos[x],pos[y],p);
	return ord[p];
}