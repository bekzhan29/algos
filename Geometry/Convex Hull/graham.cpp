struct point
{
	ll x, y;
	bool operator==(const point &a)
	{
		return x == a.x && y == a.y;
	}
	bool operator<(const point &a)
	{
		if (x != a.x)
			return x < a.x;
		return y < a.y;
	}
} a[N];
ll cross(point o, point a, point b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
vector<point> convex_hull(ll n, point a[])
{
	// https://github.com/bekzhan29/algos
	vector<point> ans;
	sort(a + 1, a + n + 1);
	ll sz = 0;
	for (ll i = 1; i <= n; i++)
	{
		while (sz >= 2 && cross(ans[sz - 1], ans[sz - 2], a[i]) >= 0)
			ans.pop_back(), sz--;
		ans.pb(a[i]);
		sz++;
	}
	ll t = sz;
	for (ll i = n - 1; i >= 1; i--)
	{
		while (sz > t && cross(ans[sz - 1], ans[sz - 2], a[i]) >= 0)
			ans.pop_back(), sz--;
		ans.pb(a[i]);
		sz++;
	}
	ans.pop_back();
	return ans;
}