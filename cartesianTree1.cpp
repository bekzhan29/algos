/*
Cartesian Tree
*/
struct item
{
	ll x,y;
	Node *l,*r;
	item(){}
	item(ll x, ll y, Node *l=NULL, Node *r=NULL):x(x),y(y),l(l),r(r){}
};
typedef item * pitem;
void merge(pitem &t, pitem l, pitem r)
{
	if(!l||!r)
	{
		t=l?l:r;
		return;
	}
	if(l->y<r->y)
		merge(l->r,l->r,r),t=l;
	else
		merge(r->l,l,r->l),t=r;
}
void split(pitem t, ll k, pitem &l, pitem &r)
{
	if(!t)
	{
		l=r=NULL;
		return;
	}
	if(t->x<=k)
		split(t->r,k,t->r,r),l=t;
	else
		split(t->l,k,l,t->l),r=t;
}
void add(pitem &t, pitem it)
{
	if(!t)
	{
		t=it;
		return;
	}
	if(it->y<t->y)
	{
		split(t,it->x,it->l,it->r);
		t=it;
		return;
	}
	if(t->x<it->x)
		add(t->r,it);
	else
		add(t->l,it);
}