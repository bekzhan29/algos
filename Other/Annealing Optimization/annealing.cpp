#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[111111], b[111111], ans, calc, l[222222], r[222222], x, y;
double t;
ll f()
{
	ll ans = 0;
	for (ll i = 1; i <= n; i++)
		ans += r[i + b[i]]++,
			ans += l[i - b[i] + n]++;
	return ans;
}
int main()
{
	cin >> n;
	for (ll i = 1; i <= n; i++)
		a[i] = b[i] = i;
	ans = f();
	srand(time(0));
	t = 10;
	for (; ans > 0;)
	{
		x = rand() % n + 1, y = rand() % n + 1;
		swap(b[x], b[y]);
		calc = ans;
		calc -= --r[x + a[x]];
		calc -= --l[x - a[x] + n];
		calc -= --r[y + a[y]];
		calc -= --l[y - a[y] + n];
		calc += r[x + b[x]]++;
		calc += l[x - b[x] + n]++;
		calc += r[y + b[y]]++;
		calc += l[y - b[y] + n]++;
		if (ans > calc || exp((ans - calc) / t) >= (rand() % 1000001) / 1000000.0)
		{
			ans = calc;
			swap(a[x], a[y]);
		}
		else
		{
			--r[x + b[x]];
			--l[x - b[x] + n];
			--r[y + b[y]];
			--l[y - b[y] + n];
			++r[x + a[x]];
			++l[x - a[x] + n];
			++r[y + a[y]];
			++l[y - a[y] + n];
			swap(b[x], b[y]);
		}
		t *= 0.99;
	}
	for (ll i = 1; i <= n; i++)
		r[i + b[i]] = l[i - b[i] + n] = 0;
	cout << f() << endl;
}