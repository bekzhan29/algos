/*
Lagrange Interpolation O(N^2logN)
1^k+2^k+...+x^k
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
#include <chrono>
#include <random>
using namespace std;
#define pb push_back
#define mp make_pair
#define INF ll(2e15)
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
const ll N=5100;
ll n,k,a[N],x,cur,ans;
ll bin(ll a, ll n)
{
	ll ans=1;
	while(n)
	{
		if(n&1)
			ans*=a,ans%=mod;
		a*=a,a%=mod;
		n/=2;
	}
	return ans;
}
ll f(ll x)
{
	ll ans=0;
	for(ll i=1;i<=x;i++)
		ans+=bin(i,k),ans%=mod;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>x>>k;
	n=k+2;
	for(ll i=1;i<=n;i++)
		a[i]=a[i-1]+bin(i,k),a[i]%=mod;
	for(ll i=1;i<=n;i++)
	{
		cur=a[i];
		for(ll j=1;j<=n;j++)
			if(i!=j)
				cur=cur*(x-j+mod)%mod*bin((i-j+mod)%mod,mod-2)%mod;
		ans+=cur;
		ans%=mod;
	}
	cout<<ans<<" "<<f(x);
}