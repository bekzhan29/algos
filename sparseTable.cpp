/*
Sparse Table build O(NlogN)
Queue O(1)
- min(l,r)
*/
ll log2[N+10],sp[20][N+10];
void build()
{
	log2[1]=0;
	for(ll i=2;i<=n;i++)
		log2[i]=log2[i/2]+1;
	for(ll i=1;i<=n;i++)
		sp[0][i]=a[i];
	for(ll j=1;j<=log2[n];j++)
		for(ll i=1;i<=n-(1<<j)+1;i++)
			sp[j][i]=min(sp[j-1][i],sp[j-1][i+(1<<(j-1))]);
}
ll getMin(ll l, ll r)
{
	ll k=log2[r-l+1];
	return min(sp[k][l],sp[k][r-(1<<k)+1]);
}