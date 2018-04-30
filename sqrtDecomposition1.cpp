/*
Sqrt Decomposition
- a[x] += y O(1)
- sum(l,r) O(sqrt(N))
*/
ll bl[N+10],len=320;
void build()
{
	for(ll i=1;i<=n;i++)
		b[i/len]+=a[i];
}
void upd(ll pos, ll k)
{
	a[pos]+=k;
	bl[pos/len]+=k;
}
ll sum(ll l, ll r)
{
	ll cl=l/len,cr=r/len,ans=0;
	if(cl==cr)
	{
		for(ll i=l;i<=r;i++)
			ans+=a[i];
		return ans;
	}
	for(ll i=l;i<(cl+1)*len;i++)
		ans+=a[i];
	for(ll i=cl+1;i<cr;i++)
		ans+=bl[i];
	for(ll i=cr*len;i<=r;i++)
		ans+=a[i];
	return ans;
}