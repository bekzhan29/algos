/*
Sparse Table
- build O(NlogN)
- sum(l,r) O(1)
*/
ll n1, lg2[2 * N], sp[20][2 * N];
void build()
{
	n1 = 1;
	while (n1 <= n)
		n1 *= 2;
	n1--;
	lg2[1] = 0;
	for (ll i = 2; i <= n1; i++)
		lg2[i] = lg2[i / 2] + 1;
	for (ll i = 1; i <= n; i++)
		sp[0][i] = a[i];
	for (ll j = 1; j <= lg2[n] + 1; j++)
		for (ll i = 0; i < n1; i += (1 << j))
		{
			ll mid = i + (1 << (j - 1)), r = min(i + (1 << j) - 1, n), sum = 0;
			for (ll k = mid; k <= r; k++)
				sum += a[k], sp[j][k] = sum;
			sum = 0;
			for (ll k = mid - 1; k >= i; k--)
				sum += a[k], sp[j][k] = sum;
		}
}
ll sum(ll l, ll r)
{
	ll k = lg2[r ^ l] + 1;
	if (l == r)
		return sp[0][l];
	return sp[k][l] + sp[k][r];
}