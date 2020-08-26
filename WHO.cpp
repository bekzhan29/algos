m=1;
for(ll i=1;i<=sz;i++)
	m*=k[i];
for(ll i=1;i<=sz;i++)
	mi[i]=m/k[i],
	rmi[i]=bin(mi[i],k[i]-k[i]/pi[i]-1,k[i]),
	c[i]=rmi[i]*re[i]%k[i];
for(ll i=1;i<=sz;i++)
	ans+=c[i]*mi[i]%m,ans%=m;