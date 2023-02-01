/*
Быстрое Преобразование Фурье
*/
double pi = acos(-1);
struct complex
{
	double x, y;
} a[N + 10], b[N + 10], c[N + 10];
complex mul(complex a, complex b)
{
	complex c;
	c.x = a.x * b.x - a.y * b.y;
	c.y = a.x * b.y + a.y * b.x;
	return c;
}
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
void fft(ll n, complex *a, bool ch)
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
		complex w, w1;
		double ang = 2 * pi / len * (ch ? -1 : 1);
		w1.x = cos(ang);
		w1.y = sin(ang);
		for (ll i = 0; i < n; i += len)
		{
			w.x = 1;
			w.y = 0;
			for (ll j = 0; j < len2; j++)
			{
				complex u = a[i + j], v = mul(a[i + j + len2], w);
				a[i + j].x = u.x + v.x;
				a[i + j].y = u.y + v.y;
				a[i + j + len2].x = u.x - v.x;
				a[i + j + len2].y = u.y - v.y;
				w = mul(w, w1);
			}
		}
	}
	if (ch)
		for (ll i = 0; i < n; i++)
			a[i].x /= n, a[i].y /= n;
}
