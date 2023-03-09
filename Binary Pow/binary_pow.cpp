int bin_pow(int a, int n, int m)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1)
            ans *= a, ans %= m;
        a = 1LL * a * a % m;
        n /= 2;
    }
    return ans;
}