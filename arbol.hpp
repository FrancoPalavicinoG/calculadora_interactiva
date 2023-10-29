#ifndef ARBOL_HPP_
#define ARBOL_HPP_

#include <iostream>
#include "treeNode.hpp"

namespace eda {

class AB {
public:
	TreeNode* root;
	AB();
	void traverse_rec(TreeNode* node, int level);
	void traverse();
	virtual ~AB();
};

}

#endif 