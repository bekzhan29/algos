template <typename Type>
struct node
{
	int n, h;
	Type val;
	node *l, *r;
	node(Type key)
	{
		n = h = 1;
		val = key;
		l = r = NULL;
	}
};
template <typename Type>
struct avl_tree
{
private:
	node<Type> *root;
	void upd(node<Type> *root)
	{
		int l_height = 0, r_height = 0, lsz = 0, rsz = 0;
		if (root->l)
			lsz = root->l->n, l_height = root->l->h;
		if (root->r)
			rsz = root->r->n, r_height = root->r->h;
		root->n = lsz + rsz + 1;
		root->h = max(l_height, r_height) + 1;
	}
	node<Type> *rotate_r(node<Type> *root)
	{
		node<Type> *a = root->l, *b = root;
		node<Type> *x = a->r;
		a->r = b;
		b->l = x;
		upd(b);
		upd(a);
		return a;
	}
	node<Type> *rotate_l(node<Type> *root)
	{
		node<Type> *a = root->r, *b = root;
		node<Type> *x = a->l;
		a->l = b;
		b->r = x;
		upd(b);
		upd(a);
		return a;
	}
	node<Type> *big_rotate_r(node<Type> *root)
	{
		root->l = rotate_l(root->l);
		return rotate_r(root);
	}
	node<Type> *big_rotate_l(node<Type> *root)
	{
		root->r = rotate_r(root->r);
		return rotate_l(root);
	}
	node<Type> *balance(node<Type> *root)
	{

		int l_height = 0, r_height = 0;
		if (root->l)
			l_height = root->l->h;
		if (root->r)
			r_height = root->r->h;
		if (abs(l_height - r_height) <= 1)
			return root;
		if (l_height > r_height)
		{
			int llh = 0;
			if (root->l->l)
				llh = root->l->l->h;
			if (llh == root->h - 2)
				return rotate_r(root);
			else
				return big_rotate_r(root);
		}
		else
		{
			int rrh = 0;
			if (root->r->r)
				rrh = root->r->r->h;
			if (rrh == root->h - 2)
				return rotate_l(root);
			else
				return big_rotate_l(root);
		}
	}
	node<Type> *insert(node<Type> *root, Type key)
	{
		if (root == NULL)
		{
			root = new node<Type>(key);
			return root;
		}
		if (key < root->val)
		{
			if (!root->l)
				root->l = new node<Type>(key);
			else
				root->l = insert(root->l, key);
		}
		else if (root->val < key)
		{
			if (!root->r)
				root->r = new node<Type>(key);
			else
				root->r = insert(root->r, key);
		}
		upd(root);
		root = balance(root);
		return root;
	}
	node<Type> *find_min(node<Type> *root)
	{
		if (!root->l)
			return root;
		return find_min(root->l);
	}
	node<Type> *erase(node<Type> *root, Type key)
	{
		if (root == NULL)
			return NULL;
		if (key < root->val)
			root->l = erase(root->l, key);
		else if (root->val < key)
			root->r = erase(root->r, key);
		else
		{
			if (!root->l || !root->r)
				return (root->l ? root->l : root->r);
			node<Type> *r_min = find_min(root->r);
			root->r = erase(root->r, r_min->val);
			root->val = r_min->val;
		}
		upd(root);
		root = balance(root);
		return root;
	}

public:
	avl_tree()
	{
		root = NULL;
	}
	int height()
	{
		if (!root)
			return 0;
		return root->h;
	}
	int size()
	{
		if (!root)
			return 0;
		return root->n;
	}
	bool empty()
	{
		return root == NULL;
	}
	Type begin()
	{
		assert(root != NULL);
		return find_min(root)->val;
	}
	void insert(Type key)
	{
		root = insert(root, key);
	}
	void erase(Type key)
	{
		root = erase(root, key);
	}
};