#ifndef TREE_HPP_
#define TREE_HPP_

#include <iostream>
#include "treeNode.hpp"

namespace eda {

class Tree {
public:
	TreeNode* root;
	Tree();
	void traverse_rec(TreeNode* node, int level);
	void traverse();
	virtual ~Tree();
};

}

#endif 