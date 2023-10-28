#ifndef TREE_STACK_HPP_
#define TREE_STACK_HPP_

#include "treeNode.hpp"
#include "ab.hpp"
#include <string>
#include <stack>

namespace eda {

class TreeStack {
private:
	TreeNode* head;
	std::stack<TreeNode*> nodeStack; // Pila para almacenar nodos
    std::stack<Tree*> treeStack;     // Pila para almacenar árboles
public:
	TreeStack();
	void push(std::string val);
	void push(TreeNode* Treenode);
	void push(Tree* tree);
	void pop();
	TreeNode* top();
	bool isEmpty();
	void clear();
	virtual ~TreeStack();
};

}

#endif