/*
Алгоритм Манакера O(N)
d1 - палиндромы нечетной длины
d2 - палиндромы четной длины
*/
ll n,d1[N],d2[N],l,r;
string s;
void build()
{
	n=s.size();
	l=r=0;
	for(ll i=1;i<=n;i++)
	{
		d1[i]=1;
		if(r>=i)
			d1[i]=min(d1[l+r-i],r-i+1);
		while(i+d1[i]<=n&&i+d1[i]>=1&&s[i+d1[i]-1]==s[i-d1[i]-1])
			d1[i]++;
		if(r<i+d1[i]-1)
			r=i+d1[i]-1,l=i-d1[i]+1;
	}
	l=r=0;
	for(ll i=1;i<=n;i++)
	{
		d2[i]=0;
		if(r>=i)
			d2[i]=min(d2[l+r-i+1],r-i+1);
		while(i+d2[i]<=n&&i-d2[i]-1>=1&&s[i+d2[i]-1]==s[i-d2[i]-2])
			d2[i]++;
		if(r<i+d2[i]-1)
			r=i+d2[i]-1,l=i-d2[i];
	}
}