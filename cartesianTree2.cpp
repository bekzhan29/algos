/*
Декартово дерево по неявному ключу
*/
struct item
{
	ll x, y, val;
	Node *l, *r;
	item() {}
	item(ll x, ll y, Node *l = NULL, Node *r = NULL) : x(x), y(y), l(l), r(r) {}
};
typedef item *pitem;
void upd(pitem &t)
{
	if (!t)
		return;
	t->x = 1;
	if (t->l)
		t->x += t->l->x;
	if (t->r)
		t->x += t->r->x;
}
void merge(pitem &t, pitem l, pitem r)
{
	if (!l || !r)
	{
		t = l ? l : r;
		return;
	}
	if (l->y < r->y)
		merge(l->r, l->r, r), t = l;
	else
		merge(r->l, l, r->l), t = r;
	upd(t);
}
void split(pitem t, ll k, pitem &l, pitem &r)
{
	if (!t)
	{
		l = r = NULL;
		return;
	}
	ll cnt = 1;
	if (t->l)
		cnt += t->l->x;
	if (cnt <= k)
		split(t->r, k - cnt, t->r, r), l = t;
	else
		split(t->l, k, l, t->l), r = t;
	upd(l);
	upd(r);
}