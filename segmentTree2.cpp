/*
Дерево отрезков сверху вниз
- upd(l, r) += k
- sum(l, r)
*/
ll tree[3*N+10],z[3*N+10];
void build(ll v, ll l, ll r)
{
	if(l==r)
	{
		tree[v]=a[l];
		z[v]=0;
		return;
	}
	ll mid=(l+r)/2;
	build(v*2,l,mid);
	build(v*2+1,mid+1,r);
	tree[v]=tree[v*2]+tree[v*2+1];
	z[v]=0;
}
void push(ll v, ll l, ll r, ll mid)
{
	if(z[v]==0)
		return;
	z[v*2]+=z[v];
	z[v*2+1]+=z[v];
	tree[v*2]+=z[v]*(mid-l+1);
	tree[v*2+1]+=z[v]*(r-mid);
	z[v]=0;
}
void upd(ll v, ll l, ll r, ll x, ll y, ll k)
{
	if(x>y||x>r||y<l)
		return;
	if(x<=l&&r<=y)
	{
		tree[v]+=(r-l+1)*k;
		z[v]+=k;
		return;
	}
	ll mid=(l+r)/2;
	push(v,l,r,mid);
	if(pos<=mid)
		upd(v*2,l,mid,x,y,k);
	else
		upd(v*2+1,mid+1,r,x,y,k);
	tree[v]=tree[v*2]+tree[v*2+1];
}
ll sum(ll v, ll l, ll r, ll x, ll y)
{
	if(x>y||x>r||y<l)
		return 0;
	if(x<=l&&r<=y)
		return tree[v];
	ll mid=(l+r)/2;
	push(v,l,r,mid)
	return sum(v*2,l,mid,x,y)+sum(v*2+1,mid+1,r,x,y);
}