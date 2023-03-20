int gcd(int a, int b)
{
	if (!b)
		return a;
	return gcd(b, a % b);
}