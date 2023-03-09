/*
Lagrange Interpolation O(NlogN)
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
const ll N = 1000100;
ll n, k, a[N], pr[N], su[N], x, cur, ans, calc;
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
ll f(ll x)
{
	ll ans = 0;
	for (ll i = 1; i <= x; i++)
		ans += bin(i, k), ans %= mod;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> x >> k;
	n = k + 2;
	if (x <= n)
		return cout << f(x), 0;
	calc = 1;
	pr[0] = su[0] = 1;
	for (ll i = 1; i <= n; i++)
	{
		a[i] = a[i - 1] + bin(i, k), a[i] %= mod;
		pr[i] = pr[i - 1] * i, pr[i] %= mod;
		su[i] = su[i - 1] * (mod - i), su[i] %= mod;
		calc *= (x - i + mod) % mod;
		calc %= mod;
	}
	for (ll i = 1; i <= n; i++)
	{
		cur = a[i] * calc % mod * bin((x - i + mod) % mod, mod - 2) % mod * bin(pr[i - 1], mod - 2) % mod * bin(su[n - i], mod - 2) % mod;
		ans += cur;
		ans %= mod;
	}
	cout << ans;
}