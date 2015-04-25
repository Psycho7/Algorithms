#include "BSTree.h"

using namespace std;

Node::Node() {
	Key = Value = 0;
	Left = Right = Parent = nullptr;
}

Node::Node(const int& key, const int& value) {
	Key = key;
	Value = value;
	Left = Right = Parent = nullptr;
}

BSTree::BSTree()
{
	root = nullptr;
}


BSTree::~BSTree()
{
}

Node *BSTree::Root() { return root; }

void BSTree::Insert(Node *k) {
	Node* y = nullptr;
	Node* x = root;
	while (x != nullptr)
	{
		y = x;
		if ( k->Key < x->Key )
			x = x->Left;
		else
			x = x->Right;
	}
	k->Parent = y;
	if ( y == nullptr )
		root = k;
	else if ( k->Key < y->Key )
		y->Left = k;
	else
		y->Right = k;
}

void BSTree::InOrderWalk(Node *p, std::function<void(Node*)> _func) {
	if ( p != nullptr )
	{
		InOrderWalk(p->Left, _func);
		_func(p);
		InOrderWalk(p->Right, _func);
	}
}

Node *BSTree::Maximum(Node *p) {
	while (p->Right != nullptr) p = p->Right;
	return p;
}

Node *BSTree::Minimum(Node *p) {
	while (p->Left != nullptr) p = p->Left;
	return p;
}

Node* BSTree::Search(int key) {
	Node* p = root;
	while ((p!=nullptr)&&(p->Key != key))
	{
		if (key < p->Key)
			p = p->Left;
		else
			p = p->Right;
	}
	return p;
}

Node *BSTree::Successor(Node *p) {
	if (p->Right) return Minimum(p->Right);
	Node *k = p->Parent;
	while (k && p==k->Right)
	{
		p = k;
		k = p->Parent;
	}
	return k;
}

Node *BSTree::Predecessor(Node *p) {
	if (p->Left) return Maximum(p->Left);
	Node *k = p->Parent;
	while (k && p==k->Left)
	{
		p = k;
		k = p->Parent;
	}
	return k;
}

void BSTree::Delete(Node *p) {
	/* TODO */
}