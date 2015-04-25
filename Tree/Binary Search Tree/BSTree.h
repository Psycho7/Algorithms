#ifndef __BSTREE__
#define __BSTREE__

#include <functional>

//typedef struct tNode Node;
struct Node {
	int Key;
	int Value;
	Node *Left;
	Node *Right;
	Node *Parent;
	Node();
	Node(const int&, const int&);
};

class BSTree
{
private:
	Node *root;
	void Transplant(Node *, Node *);
public:
	BSTree();
	~BSTree();
	Node *Root();
	Node *Maximum(Node*);
	Node *Minimum(Node*);
	void Insert(Node*);
	Node *Search(int);
	void Delete(Node*);
	Node *Successor(Node*);
	Node *Predecessor(Node*);
	void InOrderWalk(Node*, std::function<void(Node*)>);
};

#endif // __BSTREE__