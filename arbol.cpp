#include "arbol.hpp"
#include <string>
#include <iostream>

namespace eda {

AB::AB():root(nullptr) {}

void AB::traverse_rec(eda::TreeNode* node, int level){
	if (node != nullptr){
		std::cout << std::string(level*2, '-');
		std::cout << " " << node->getData() << std::endl;
		traverse_rec(node->getLeft(), level + 1);
		traverse_rec(node->getRight(), level + 1);
	}
}

void AB::traverse(){
	traverse_rec(root, 1);
}

AB::~AB() {
	delete root;
}

}
