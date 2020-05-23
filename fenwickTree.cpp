/*
Дерево Фенвика O(NlogN)
- Сумма на отрезке O(logN)
- a[x] += y O(logN)
*/
ll tree[N+10];
void add(ll pos, ll x)
{
	for(;pos<=n;pos=(pos|(pos+1)))
		tree[pos]+=x;
}
ll sum(ll pos)
{
	ll ans=0;
	for(;pos>=0;pos=(pos&(pos+1))-1)
		ans+=tree[pos];
	return ans;
}
void init()
{
	for(ll i=0;i<=n;i++)
		tree[i]=0;
	for(ll i=1;i<=n;i++)
		add(i,a[i]);
}