#include "tree.hpp"
#include <string>
#include <iostream>

namespace eda {

Tree::Tree():root(nullptr) {}

void Tree::traverse_rec(eda::TreeNode* node, int level){
	if (node != nullptr){
		std::cout << std::string(level*2, '-');
		std::cout << " " << node->getData() << std::endl;
		traverse_rec(node->getLeft(), level + 1);
		traverse_rec(node->getRight(), level + 1);
	}
}

void Tree::traverse(){
	traverse_rec(root, 1);
}

Tree::~Tree() {
	delete root;
}

}
