/*
Task: https://atcoder.jp/contests/abc285/tasks/abc285_h
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define INF ll(1e18)
#define mod2 998244353
#define mod 1000000007
#define eps 1e-9
#define abs(x) ((x) >= 0 ? (x) : -(x))
#define y1 solai
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<pll, ll> plll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll N = 10100;
ll n, k, a[N], x[N], f[N], rf[N], ans;
ll bin(ll a, ll n)
{
	ll ans = 1;
	while (n)
	{
		if (n & 1)
			ans *= a, ans %= mod;
		a *= a, a %= mod;
		n /= 2;
	}
	return ans;
}
ll c(ll n, ll k)
{
	if (k < 0 || k > n)
		return 0;
	return f[n] * rf[k] % mod * rf[n - k] % mod;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	f[0] = 1;
	for (ll i = 1; i <= n; i++)
		f[i] = f[i - 1] * i % mod;
	rf[n] = bin(f[n], mod - 2);
	for (ll i = n - 1; i >= 0; i--)
		rf[i] = rf[i + 1] * (i + 1) % mod;
	for (ll i = 1; i <= k; i++)
		cin >> a[i];
	x[0] = 1;
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j < N; j++)
			x[j] += x[j - 1], x[j] %= mod;
	for (ll i = 0; i <= n; i++)
	{
		ll cur = c(n, i);
		if (i & 1)
			cur = mod - cur;
		for (ll j = 1; j <= k; j++)
			cur *= x[a[j]], cur %= mod;
		ans += cur;
		ans %= mod;
		for (ll i = N - 1; i >= 1; i--)
			x[i] += mod - x[i - 1], x[i] %= mod;
		for (ll i = 2; i < N; i++)
			x[i] += x[i - 2], x[i] %= mod;
	}
	cout << ans;
}
