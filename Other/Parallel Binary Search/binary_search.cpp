/*
https://github.com/bekzhan29/algos
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define INF ll(2e15)
#define mod 998244353
#define mod2 1000000007
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
const ll N = 200100;
ll n, m, x[N], y[N], z[N], a[N], b[N], q, ans[N], l[N], r[N], mid, id[N];
vector<ll> v;
ll p[N], sz[N];
ll fin(ll a)
{
	if (a == p[a])
		return a;
	return p[a] = fin(p[a]);
}
bool uni(ll a, ll b)
{
	a = fin(a), b = fin(b);
	if (a == b)
		return 0;
	if (sz[a] > sz[b])
		sz[a] += sz[b], p[b] = a;
	else
		sz[b] += sz[a], p[a] = b;
	return 1;
}
void init_dsu(ll n)
{
	for (ll i = 1; i <= n; i++)
		p[i] = i, sz[i] = 1;
}
bool cmp(ll a, ll b)
{
	return l[a] < l[b];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (ll i = 1; i <= m; i++)
		cin >> a[i] >> b[i];
	cin >> q;
	for (ll i = 1; i <= q; i++)
		cin >> x[i] >> y[i] >> z[i], v.pb(i), l[i] = 1, r[i] = m, id[i] = i;
	for (;;)
	{
		sort(id + 1, id + q + 1, &cmp);
		init_dsu(n);
		ll cnt = 0, pos = 0;
		for (ll j = 1; j <= q; j++)
		{
			ll i = id[j];
			mid = (l[i] + r[i]) / 2;
			while (pos < mid)
			{
				pos++;
				uni(a[pos], b[pos]);
			}
			ll calc = sz[fin(x[i])];
			if (fin(x[i]) != fin(y[i]))
				calc += sz[fin(y[i])];
			if (calc >= z[i])
				r[i] = mid;
			else
				l[i] = mid + 1;
			if (l[i] == r[i])
				cnt++;
		}
		if (cnt == q)
			break;
	}
	for (ll i = 1; i <= q; i++)
		cout << l[i] << "\n";
}