bool BSTree::search(const int e, BSTNode * f, BSTNode * p)

{
	BSTNode * f , p;
	f = NULL;
	P = this->root;
	while(p && p->data != e)
	{
		f = p;
		if( e < p->data)
			p = p->l;
		else
			p= p->r;

	}

	return p!=NULL;



}

bool BSTree::insert(const int e)
{
	BSTNode *p,*s,*f;
	if(!search(e,f,p))
	{
		nn =new BSTNode;
		nn->data = e;
		nn->l =n->r = NULL;
		if(!f)
			root =s;
		else if(e < f->data)
			f->l = s;
		else 
			f->r = s;
		return true;

	}

	return false;

}
bool BSTree::delete(const int e)
{
	BSTNode *p , *f;
	if(!search(e, p, f))
		return false;

	if(!p->r)
	{
		if(f == NULL)
			root = p>l;
		else
		{
			if(f->l == p)
				f->l = p->l;
			else
				f->r = p->l;
		}
		delete p;
	}
	else if(!p->l)
	{
		if(f == NULL)
			root = p->r;
		else
		{

			if(f->l == p)
				f->l = p->r;
			else
				f->r = p->r;

		}
		delete p;

	}
	else
	{
		BSTNode * nn;
		f= p;
		nn = p->l;
		while(nn->r)
		{
			f = nn;
			nn = nn->r;
		}
		p->data = nn->data;
		if(f != p)
			f->r = nn->l;
		else
			f->l = s->l;
		delete nn;
	}
	return true;
}