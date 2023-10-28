#include "ab.hpp"
#include <string>
#include <iostream>

namespace eda {

Tree::Tree():root(nullptr) {}

void Tree::insert(std::string val) {
    if (root == nullptr) {
        root = new TreeNode(val);
		std::cout << "root: " << val << std::endl;

    } else {
        insert_rec(val, root);
    }
}

void Tree::insert_rec(std::string val, TreeNode* node) {
    if (node->getLeft() == nullptr) {
        node->setLeft(new TreeNode(val));
        std::cout << val << " inserted on left of " << node->getData() << std::endl;
    } else if (node->getRight() == nullptr) {
        node->setRight(new TreeNode(val));
        std::cout << val << " inserted on right of " << node->getData() << std::endl;
    } else {
        // Both left and right children are occupied, create a new tree
        TreeNode* new_tree = new TreeNode(val);
        // Now, make the existing node the left child of the new tree
        new_tree->setLeft(node);
		std::cout << node->getData() << " inserted on left of " << new_tree->getData() << std::endl;

        // Set the new tree as the root of the Tree object
        root = new_tree;
		std::cout << "root: " << root->getData() << std::endl;

    }
}

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

void Tree::setRoot(TreeNode* root) {
    this->root = root;
}

TreeNode* Tree::getRoot() {
    return root;
}

Tree::~Tree() {
	delete root;
}

} /* namespace trees */
