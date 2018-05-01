/*
Биномиальная пирамида
- объединить 2 пирамиды O(logN)
- найти минимум O(logN)
- добавить элемент O(logN)
- удалить минимум O(logN)
*/
ll head,val[N+10],sib[N+10],son[N+10],par[N+10],sz[N+10];
ll uni(ll x, ll y)
{
	if(val[x]<val[y])
		swap(x,y);
	par[x]=y;
	sib[x]=son[y];
	son[y]=x;
	sz[y]++;
	return y;
}
ll merge(ll x, ll y)
{
	ll head=0,cur=0,last=0,next,go;
	if(!x||!y)
		return x?x:y;
	if(sz[x]<sz[y])
		head=cur=x,x=sib[x];
	else
		head=cur=y,y=sib[y];
	while(x&&y)
	{
		if(sz[x]<sz[y])
			sib[cur]=x,cur=x,x=sib[x];
		else
			sib[cur]=y,cur=y,y=sib[y];
	}
	while(x)
		sib[cur]=x,cur=x,x=sib[x];
	while(y)
		sib[cur]=y,cur=y,y=sib[y];
	cur=head;
	while(cur)
	{
		if(sib[cur]>0)
			next=sib[cur];
		if(sz[cur]==sz[next]&&(sib[next]==0||sz[sib[next]]!=sz[next]))
		{
			go=sib[next];
			cur=uni(cur,next);
			if(last>0)
				sib[last]=cur;
			else
				head=cur;
			sib[cur]=go;
		}
		last=cur;
		cur=sib[cur];
	}
	return head;
}
ll getMin(ll head)
{
	ll ans=val[head];
	while(head)
	{
		ans=min(ans,val[head]);
		head=sib[head];
	}
	return ans;
}