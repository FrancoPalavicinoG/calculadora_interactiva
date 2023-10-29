#include "treeNode.hpp"
#include <iostream>
#include <string>

namespace eda {

TreeNode::TreeNode() : data(""), ptrNext(nullptr), ptrLeft(nullptr), ptrRight(nullptr), size(0) {
}

TreeNode::TreeNode(std::string val) : data(val), ptrNext(nullptr), ptrLeft(nullptr), ptrRight(nullptr), size(0) {
}

TreeNode* TreeNode::create_node(std::string data) {
    TreeNode* new_node = new TreeNode();
    new_node->data = data;
    new_node->ptrLeft = nullptr;
    new_node->ptrRight = nullptr;
    return new_node;
}

void TreeNode::setData(std::string _data){
	data = _data;
}

void TreeNode::setNext(TreeNode* next){
	ptrNext = next;
}

std::string TreeNode::getData(){
	return data;
}
TreeNode* TreeNode::getNext(){
	return ptrNext;
}

void TreeNode::print(){
	std::cout << data ;
}

void TreeNode::setLeft(TreeNode* node){
    ptrLeft = node;
}

void TreeNode::setRight(TreeNode* node){
    ptrRight = node;
}

void TreeNode::setSize(int s){
    size = s;
}

TreeNode* TreeNode::getLeft(){
    return ptrLeft;
}

TreeNode* TreeNode::getRight(){
    return ptrRight;
}

int TreeNode::getSize(){
    return size;
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
