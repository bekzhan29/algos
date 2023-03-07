/*
Быстрое Преобразование Фурье. /* test, do not merge */
*/
double pi = acos(-1);
struct complexx
{
	double x, y;
	complexx(double x = 0, double y = 0) : x(x), y(y) {}
	complexx operator*(const complexx &a)
	{
		complexx c;
		c.x = x * a.x - y * a.y;
		c.y = x * a.y + y * a.x;
		return c;
	}
} a[N], b[N], c[N];
ll rev(ll x, ll n)
{
	ll ans = 0;
	for (ll i = 1; i <= n; i++)
	{
		ans = ans * 2 + x % 2;
		x /= 2;
	}
	return ans;
}
void fft(ll n, complexx *a, bool ch)
{
	ll log = 0;
	while ((1 << log) < n)
		log++;
	for (ll i = 0; i < n; i++)
	{
		ll j = rev(i, log);
		if (i < j)
			swap(a[i], a[j]);
	}
	for (ll len = 2; len <= n; len *= 2)
	{
		ll len2 = len / 2;
		complexx w, w1;
		double ang = 2 * pi / len * (ch ? -1 : 1);
		w1 = complexx(cos(ang), sin(ang));
		for (ll i = 0; i < n; i += len)
		{
			w.x = 1;
			w.y = 0;
			for (ll j = 0; j < len2; j++)
			{
				complexx u = a[i + j], v = a[i + j + len2] * w;
				a[i + j].x = u.x + v.x;
				a[i + j].y = u.y + v.y;
				a[i + j + len2].x = u.x - v.x;
				a[i + j + len2].y = u.y - v.y;
				w = w * w1;
			}
		}
	}
	if (ch)
		for (ll i = 0; i < n; i++)
			a[i].x /= n, a[i].y /= n;
}
