#include <iostream>
#include <cstdlib>
#include <functional>
#include <vector>
#include "BSTree.h"

using namespace std;

int main() {
	BSTree tree;
	srand(123);
	for (int i = 0; i < 10; i++) {
		int value = rand() % 100;
		Node *node = new Node(value, value);
		tree.Insert(node);
	}
	vector<Node *> f;
	function<void(Node *)> func = [&f](Node *p) {
		f.push_back(p);
	};
	tree.InOrderWalk(tree.Root(), func);
	for (vector<Node *>::iterator i = f.begin(); i != f.end(); i++)
	{
		cout << (*i)->Value << endl;
	}
}