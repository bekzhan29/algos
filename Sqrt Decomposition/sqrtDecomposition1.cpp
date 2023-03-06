/*
Sqrt Decomposition
- a[x] += y O(1)
- sum(l,r) O(sqrt(N))
*/
template <typename Type>
struct sqrt_dec
{
	ll len = 320;
	Type a[N], bl[N];
	void build(ll n, Type *a)
	{
		len = sqrt(n);
		for (ll i = 1; i <= n; i++)
		{
			this->a[i] = a[i];
			bl[i / len] += a[i];
		}
	}
	void upd(ll pos, Type k)
	{
		a[pos] += k;
		bl[pos / len] += k;
	}
	Type sum(ll l, ll r)
	{
		Type ans = 0;
		ll cl = l / len, cr = r / len;
		if (cl == cr)
		{
			for (ll i = l; i <= r; i++)
				ans += a[i];
			return ans;
		}
		for (ll i = l; i < (cl + 1) * len; i++)
			ans += a[i];
		for (ll i = cl + 1; i < cr; i++)
			ans += bl[i];
		for (ll i = cr * len; i <= r; i++)
			ans += a[i];
		return ans;
	}
};