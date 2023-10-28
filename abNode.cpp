#include "abNode.hpp"
#include <string>

namespace eda {

ABNode::ABNode():
		ptrLeft(nullptr), data(""), ptrRight(nullptr) {
	// TODO Auto-generated constructor stub
}

ABNode::ABNode(std::string val):
		ptrLeft(nullptr), data(val), ptrRight(nullptr){

}

void ABNode::setLeft(ABNode* node){
	ptrLeft = node;
}

void ABNode::setRight(ABNode* node){
	ptrRight = node;
}

void ABNode::setData(std::string val){
	data = val;
}

void ABNode::setSize(int s){
	size = s;
}

ABNode* ABNode::getLeft(){
	return ptrLeft;
}

ABNode* ABNode::getRight(){
	return ptrRight;
}

std::string ABNode::getData(){
	return data;
}

int ABNode::getSize(){
	return size;
}

ABNode::~ABNode() {
	if (ptrLeft != nullptr){
		delete ptrLeft;
	}
	if (ptrRight != nullptr){
		delete ptrRight;
	}
}

}
