/*
Теорема Лукаса O(P)
*/
ll f[N], rf[N];
ll bin(ll a, ll n, ll p)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1)
            ans *= a, ans %= p;
        a *= a, a %= p;
        n /= 2;
    }
    return ans;
}
void init(ll p)
{
    f[0] = 1;
    for (ll i = 1; i < p; i++)
        f[i] = f[i - 1] * i % p;
    rf[p - 1] = bin(f[p - 1], p - 2, p);
    for (ll i = p - 2; i >= 0; i--)
        rf[i] = rf[i + 1] * (i + 1) % p;
}
ll c(ll n, ll k, ll p)
{
    if (k < 0 || k > n)
        return 0;
    return f[n] * rf[k] % p * rf[n - k] % p;
}
ll lucas(ll n, ll k, ll p)
{
    if (k < 0 || k > n)
        return 0;
    ll ans = 1;
    while (n)
    {
        ans *= c(n % p, k % p, p);
        ans %= p;
        n /= p;
        k /= p;
    }
    return ans;
}