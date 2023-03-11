/*
https://github.com/bekzhan29/algos/

Task: https://atcoder.jp/contests/abc293/tasks/abc293_g
*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<ll, ll> pll;
const ll N = 200400;
ll n, m, a[N], l, r, k, cnt[N], ans[N], res, tl, tr, pos;
vector<pair<pll, ll>> v[N];
void mo()
{
	for (ll i = 0; i <= n / k; i++)
	{
		for (ll j = 0; j < N; j++)
			cnt[j] = 0;
		res = 0;
		l = 1, r = 0;
		sort(v[i].begin(), v[i].end());
		for (ll j = 0; j < v[i].size(); j++)
		{
			tl = v[i][j].fi.se;
			tr = v[i][j].fi.fi;
			pos = v[i][j].se;
			while (r < tr)
			{
				cnt[a[++r]]++;
				if (cnt[a[r]] >= 3)
					res += (cnt[a[r]] - 1) * (cnt[a[r]] - 2) / 2;
			}
			while (l < tl)
			{
				ll x = a[l++];
				cnt[x]--;
				if (cnt[x] >= 2)
					res -= cnt[x] * (cnt[x] - 1) / 2;
			}
			while (l > tl)
			{
				ll x = a[--l];
				cnt[x]++;
				if (cnt[x] >= 3)
					res += (cnt[x] - 1) * (cnt[x] - 2) / 2;
			}
			ans[pos] = res;
		}
	}
}
int main()
{
	cin >> n >> m;
	k = sqrt(n);
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	for (ll i = 1; i <= m; i++)
		cin >> l >> r, v[l / k].push_back({{r, l}, i});
	mo();
	for (ll i = 1; i <= m; i++)
		cout << ans[i] << "\n";
}