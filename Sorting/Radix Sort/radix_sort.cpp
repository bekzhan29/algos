void radix_sort(int *a, int l, int r, int base = 10)
{
	// https://github.com/bekzhan29/algos
	if (l >= r)
		return;
	vector<pair<int, int>> b, c[base];
	int mx = a[l];
	for (int i = l; i <= r; i++)
	{
		b.push_back({a[i], a[i]});
		mx = max(mx, a[i]);
	}
	int len = 0;
	while (mx)
	{
		mx /= base;
		len++;
	}
	for (int k = 1; k <= len; k++)
	{
		for (auto x : b)
			c[x.fi % base].push_back({x.fi / base, x.se});
		b.clear();
		for (int i = 0; i < base; i++)
		{
			for (auto x : c[i])
				b.push_back(x);
			c[i].clear();
		}
	}
	for (int i = l; i <= r; i++)
		a[i] = b[i - l].se;
}