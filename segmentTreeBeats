/*
Segment tree beats O(Nlog^2N)
1. Вывести сумму на отрезке l,r
2. Взять по модулю на отрезке l,r a[i]%=x
3. Обновление a[i]=x
*/
const ll N=100100;
ll a[N];
struct item
{
	ll sum,mx,mn,z;
}t[4*N];
item merge(item a, item b)
{
	item c;
	c.sum=a.sum+b.sum;
	c.mx=max(a.mx,b.mx);
	c.mn=min(a.mn,b.mn);
	c.z=-1;
	return c;
}
void push(ll v, ll l, ll r, ll mid)
{
	if(t[v].z<0)
		return;
	x=t[v].z;
	t[v*2]={(mid-l+1)*x,x,x,x};
	t[v*2+1]={(r-mid)*x,x,x,x};
	t[v].z=-1;
}
void build(ll v, ll l, ll r)
{
	if(l==r)
	{
		t[v]={a[l],a[l],a[l],-1};
		return;
	}
	ll mid=(l+r)/2;
	build(v*2,l,mid);
	build(v*2+1,mid+1,r);
	t[v]=merge(t[v*2],t[v*2+1]);
}
void upd(ll v, ll l, ll r, ll x, ll y, ll k)
{
	if(x>y||x>r||y<l||t[v].mx<k)
		return;
	if(x<=l&&r<=y&&t[v].mn==t[v].mx)
	{
		ll cur=t[v].mx%k;
		t[v]={cur*(r-l+1),cur,cur,cur};
		return;
	}
	ll mid=(l+r)/2;
	push(v,l,r,mid);
	upd(v*2,l,mid,x,y,k);
	upd(v*2+1,mid+1,r,x,y,k);
	t[v]=merge(t[v*2],t[v*2+1]);
}
void upd2(ll v, ll l, ll r, ll x, ll y)
{
	if(l==r)
	{
		t[v]={y,y,y,-1};
		return;
	}
	ll mid=(l+r)/2;
	push(v,l,r,mid);
	if(x<=mid)
		upd2(v*2,l,mid,x,y);
	else
		upd2(v*2+1,mid+1,r,x,y);
	t[v]=merge(t[v*2],t[v*2+1]);
}
ll sum(ll v, ll l, ll r, ll x, ll y)
{
	if(x>y||x>r||y<l)
		return 0;
	if(x<=l&&r<=y)
		return t[v].sum;
	ll mid=(l+r)/2;
	push(v,l,r,mid);
	return sum(v*2,l,mid,x,y)+sum(v*2+1,mid+1,r,x,y);
}