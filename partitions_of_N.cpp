/*
Количество разбиений числа N на слагаемые O(NsqrtN)
*/
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
#define pb push_back
#define INF 2e14
#define mod 998244353
#define eps 1e-9
#define abs(x) ((x) >= 0 ? (x) : -(x))
#define y1 solai
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
const ll N = 1000100;
ll n, d[N];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	d[0] = 1;
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; (3 * j * j - j) / 2 <= i; j++)
		{
			d[i] += (j % 2 ? 1 : -1) * d[i - (3 * j * j - j) / 2];
			if ((3 * j * j + j) / 2 <= i)
				d[i] += (j % 2 ? 1 : -1) * d[i - (3 * j * j + j) / 2];
			d[i] %= mod;
		}
	cout << d[n];
}
