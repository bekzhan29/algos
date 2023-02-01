/*
Персистентное дерево отрезков
- a[x] += y O(logN)
- sum(l, r) в версии i O(logN)
*/
ll a[N + 10], root[N + 10], sz;
struct node
{
	ll sum, l, r;
	node() : sum(0), l(0), r(0) {}
} tree[N + 10];
void build(ll &v, ll l, ll r)
{
	if (!v)
		v = ++sz;
	if (l == r)
	{
		tree[v].sum = a[l];
		return;
	}
	ll mid = (l + r) / 2;
	build(tree[v].l, l, mid);
	build(tree[v].r, mid + 1, r);
	ll left = tree[v].l, right = tree[v].r;
	tree[v].sum = tree[left].sum + tree[right].sum;
}
void upd(ll v1, ll &v2, ll l, ll r, ll pos, ll k)
{
	if (!v2)
		v2 = ++sz;
	if (l == r)
	{
		tree[v2].sum = tree[v1].sum + k;
		return;
	}
	ll mid = (l + r) / 2;
	if (pos <= mid)
		tree[v2].r = tree[v1].r,
		upd(tree[v1].l, tree[v2].l, l, mid, pos, k);
	else
		tree[v2].l = tree[v1].l,
		upd(tree[v1].r, tree[v2].r, mid + 1, r, pos, k);
	ll left = tree[v2].l, right = tree[v2].r;
	tree[v2].sum = tree[left].sum + tree[right].sum;
}
ll sum(ll v, ll l, ll r, ll x, ll y)
{
	if (x > y || x > r || y < l)
		return 0;
	if (x <= l && r <= y)
		return tree[v].sum;
	ll mid = (l + r) / 2;
	return sum(tree[v].l, l, mid, x, y) + sum(tree[v].r, mid + 1, r, x, y);
}
