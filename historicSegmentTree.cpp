/*
Historic segment tree
1. a[i]+=x на отрезке l,r
2. a[i]=max(a[i]-x,0) на отрезке l,r
3. a[i]=x на отрезке l,r
4. вывести a[i]
5. вывести b[i]
b[i] = максимальное значение a[i] за все время
Задача - https://uoj.ac/problem/164
Пост - https://codeforces.com/blog/entry/57319
*/
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
#define pb push_back
#define INF ll(2e18)
#define mod 998244353
#define eps 1e-9
#define abs(x) ((x)>=0?(x):-(x))
#define y1 solai
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
const ll N=500100;
ll n,m,a[N],ty,l,r,x;
struct item
{
	ll x,y,xb,yb;
}t[4*N];
item merge(item a, item b)
{
	item c={a.x+b.x,max(a.y+b.x,b.y)};
	c.x=max(c.x,-INF);
	c.xb=max({a.xb,a.x+b.xb,c.x});
	c.xb=max(c.xb,-INF);
	c.yb=max({a.yb,a.y+b.xb,b.yb,c.y});
	return c;
}
void push(ll v)
{
	t[v*2]=merge(t[v*2],t[v]);
	t[v*2+1]=merge(t[v*2+1],t[v]);
	t[v]={0,-INF,0,-INF};
}
void build(ll v, ll l, ll r)
{
	if(l==r)
	{
		t[v]={0,-INF,0,-INF};
		return;
	}
	ll mid=(l+r)/2;
	build(v*2,l,mid);
	build(v*2+1,mid+1,r);
	t[v]={0,-INF,0,-INF};
}
void upd(ll v, ll l, ll r, ll x, ll y, item cur)
{
	if(x>y||x>r||y<l)
		return;
	if(x<=l&&r<=y)
	{
		t[v]=merge(t[v],cur);
		return;
	}
	ll mid=(l+r)/2;
	push(v);
	upd(v*2,l,mid,x,y,cur);
	upd(v*2+1,mid+1,r,x,y,cur);
}
ll get(ll q, ll v, ll l, ll r, ll x)
{
	if(l==r)
	{
		if(q==1)
			return max(a[l]+t[v].x,t[v].y);
		return max(a[l]+t[v].xb,t[v].yb);
	}
	ll mid=(l+r)/2;
	push(v);
	if(x<=mid)
		return get(q,v*2,l,mid,x);
	return get(q,v*2+1,mid+1,r,x);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	for(ll i=1;i<=m;i++)
	{
		cin>>ty>>l;
		if(ty<=3)
			cin>>r>>x;
		if(ty==1)
			upd(1,1,n,l,r,{x,-INF,0,-INF});
		if(ty==2)
			upd(1,1,n,l,r,{-x,0,0,-INF});
		if(ty==3)
			upd(1,1,n,l,r,{-INF,x,0,-INF});
		if(ty==4)
			cout<<get(1,1,1,n,l)<<"\n";
		if(ty==5)
			cout<<get(2,1,1,n,l)<<"\n";
	}
}