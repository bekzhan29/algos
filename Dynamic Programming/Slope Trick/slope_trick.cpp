#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define INF ll(2e9)
#define mod 998244353
#define eps 1e-9
#define abs(x) ((x) >= 0 ? (x) : -(x))
#define y1 solai
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ll N = 100100;
ll n, x, ans;
priority_queue<ll> q;
int main()
{
	// https://github.com/bekzhan29/algos
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		cin >> x, x -= i;
		q.push(x);
		q.push(x);
		ans += q.top() - x;
		q.pop();
	}
	cout << ans;
}