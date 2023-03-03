ll mul(ll a, ll b, ll m)
{
	ll q = (ll)((long double)a * (long double)b / (long double)m);
	ll r = a * b - q * m;
	return (r + 5 * m) % m;
}