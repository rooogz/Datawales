#ifndef _BST_H_
#define   _BST_H_
struct BSTNode
{
	int data;
	BSTNode * l;
	BSTNode * r;

}


class BSTree
{
	public:
		BSTree();
		~BSTree();
		bool search(const int e, BSTNode * f, BSTNode * p) const;
		bool insert(const int & e);
	private:
		BSTNode * root;


}

#endif