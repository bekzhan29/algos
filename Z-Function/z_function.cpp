/* 
Z function
- Description: for a string s, returns an array of length n where the i'th element is equal to the 
greatest number of characters starting from the position i that coincide with the 
first characters of s.
- Complexity: O(|s|)
*/
vector<int> z_function(string s)
{
	int n = s.size();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; i++)
	{
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;
		if (i + z[i] - 1 > r)
		{
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}
