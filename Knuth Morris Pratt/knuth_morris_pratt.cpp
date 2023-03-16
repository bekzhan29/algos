ll n, p[N];
string s;
void build()
{
	// https://github.com/bekzhan29/algos
	n = s.size();
	for (ll i = 1; i < n; i++)
	{
		ll j = p[i - 1];
		while (j > 0 && s[j] != s[i])
			j = p[j - 1];
		if (s[i] == s[j])
			j++;
		p[i] = j;
	}
}