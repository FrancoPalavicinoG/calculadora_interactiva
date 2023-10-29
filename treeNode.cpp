#include "treeNode.hpp"
#include <iostream>
#include <string>

namespace eda {

TreeNode::TreeNode() : data(""), ptrLeft(nullptr), ptrRight(nullptr) {
}

TreeNode::TreeNode(std::string val) : data(val), ptrLeft(nullptr), ptrRight(nullptr) {
}

TreeNode* TreeNode::setter(std::string data) {
    TreeNode* new_node = new TreeNode();
    new_node->data = data;
    new_node->ptrLeft = nullptr;
    new_node->ptrRight = nullptr;
    return new_node;
}

void TreeNode::setData(std::string _data){
	data = _data;
}

std::string TreeNode::getData(){
	return data;
}

void TreeNode::setLeft(TreeNode* node){
    ptrLeft = node;
}

void TreeNode::setRight(TreeNode* node){
    ptrRight = node;
}

TreeNode* TreeNode::getLeft(){
    return ptrLeft;
}

TreeNode* TreeNode::getRight(){
    return ptrRight;
}

TreeNode::~TreeNode() {
    if (ptrLeft != nullptr){
        delete ptrLeft;
    }
    if (ptrRight != nullptr){
        delete ptrRight;
    }
}
}
