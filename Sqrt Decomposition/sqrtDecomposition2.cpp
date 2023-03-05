/*
Sqrt Decomposition
- upd(l,r)+=k O(sqrt(N))
- sum(l,r) O(sqrt(N))
*/
ll bl[N], zl[N], len = 320;
void build()
{
	for (ll i = 1; i <= n; i++)
		bl[i / len] += a[i];
}
void push(ll pos)
{
	if (zl[pos] == 0)
		return;
	for (ll i = pos * len; i < (pos + 1) * len; i++)
		a[i] += zl[pos];
	zl[pos] = 0;
}
void upd(ll l, ll r, ll k)
{
	ll cl = l / len, cr = r / len;
	if (cl == cr)
	{
		push(cl);
		for (ll i = l; i <= r; i++)
			a[i] += k, bl[cl] += k;
		return;
	}
	push(cl);
	push(cr);
	for (ll i = l; i < (cl + 1) * len; i++)
		a[i] += k, bl[cl] += k;
	for (ll i = cl + 1; i < cr; i++)
		zl[i] += k, bl[i] += len * k;
	for (ll i = cr * len; i <= r; i++)
		a[i] += k, bl[cr] += k;
}
ll sum(ll l, ll r)
{
	ll cl = l / len, cr = r / len, ans = 0;
	if (cl == cr)
	{
		push(cl);
		for (ll i = l; i <= r; i++)
			ans += a[i];
		return ans;
	}
	push(cl);
	push(cr);
	for (ll i = l; i < (cl + 1) * len; i++)
		ans += a[i];
	for (ll i = cl + 1; i < cr; i++)
		ans += bl[i];
	for (ll i = cr * len; i <= r; i++)
		ans += a[i];
	return ans;
}