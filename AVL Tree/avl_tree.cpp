template <typename Type>
struct avl_tree
{
	int n, h;
	Type val;
	avl_tree *l, *r;
	avl_tree()
	{
		n = h = 0;
		l = r = NULL;
	}
	avl_tree(Type key)
	{
		val = key;
		n = h = 1;
		l = r = NULL;
	}
	int size()
	{
		return n;
	}
	bool empty()
	{
		return n == 0;
	}
	void upd(avl_tree *root)
	{
		int l_height = 0, r_height = 0, lsz = 0, rsz = 0;
		if (root->l)
			lsz = root->l->n, l_height = root->l->h;
		if (root->r)
			rsz = root->r->n, r_height = root->r->h;
		root->n = lsz + rsz + 1;
		root->h = max(l_height, r_height) + 1;
	}
	avl_tree *rotate_r(avl_tree *root)
	{
		avl_tree *a = root->l, *b = root;
		avl_tree *x = a->r;
		a->r = b;
		b->l = x;
		return a;
	}
	avl_tree *rotate_l(avl_tree *root)
	{
		avl_tree *a = root->r, *b = root;
		avl_tree *x = a->l;
		a->l = b;
		b->r = x;
		return a;
	}
	avl_tree *big_rotate_r(avl_tree *root)
	{
		root->l = rotate_l(root->l);
		return rotate_r(root);
	}
	avl_tree *big_rotate_l(avl_tree *root)
	{
		root->r = rotate_r(root->r);
		return rotate_l(root);
	}
	avl_tree *balance(avl_tree *root)
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
			if(rrh == root->h - 2)
				return rotate_l(root);
			else
				return big_rotate_r(root);
		}
	}
	void insert(Type key)
	{
		if (n == 0)
		{
			n++;
			h++;
			val = key;
			return;
		}
		if (key < val)
		{
			if (!l)
				l = new avl_tree(key);
			else
				l->insert(key);
		}
		else if (val < key)
		{
			if (!r)
				r = new avl_tree(key);
			else
				r->insert(key);
		}
		upd(this);
		// balance(this);
	}
	avl_tree *find_min(avl_tree *root)
	{
		if (!root->l)
			return root;
		return find_min(root->l);
	}
	avl_tree *erase(avl_tree *root, Type key)
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
			avl_tree *r_min = find_min(root->r);
			root->r = erase(root->r, r_min->val);
			root->val = r_min->val;
		}
		upd(root);
		root = balance(root);
		return root;
	}
	Type begin()
	{
		assert(n > 0);
		return find_min(this)->val;
	}
};