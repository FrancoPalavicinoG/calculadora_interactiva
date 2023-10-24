#include "abNode.hpp"

namespace trees {

ABNode::ABNode():
		ptrLeft(nullptr), data(-1), ptrRight(nullptr) {
	// TODO Auto-generated constructor stub
}

ABNode::ABNode(int val):
		ptrLeft(nullptr), data(val), ptrRight(nullptr){

}

void ABNode::setLeft(ABNode* node){
	ptrLeft = node;
}

void ABNode::setRight(ABNode* node){
	ptrRight = node;
}

void ABNode::setData(int val){
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

int ABNode::getData(){
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
