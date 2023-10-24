#include "ab.hpp"
#include <iostream>

namespace trees {

AB::AB():root(nullptr) {}

void AB::insert_rec(int val, ABNode* node){
	if (val < node->getData()){
		//LEFT
		if (node->getLeft() == nullptr){
			node->setLeft(new ABNode(val));
			std::cout<<val << " inserted on left" << std::endl;
		}
		else{
			insert_rec(val, node->getLeft());
		}
	}
	else{
		//RIGHT
		if (node->getRight() == nullptr){
			node->setRight(new ABNode(val));
			std::cout<<val << " inserted on right" << std::endl;
		}
		else{
			insert_rec(val, node->getRight());
		}
	}
}

void AB::insert(int val){
	if (root == nullptr){
		root = new ABNode(val);
	}
	else{
		insert_rec(val, root);
	}
}

void AB::traverse_rec(ABNode* node, int level){
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

} /* namespace trees */
