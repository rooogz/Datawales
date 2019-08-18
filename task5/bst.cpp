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