#include "node.hpp"
#include <iostream>

namespace eda {


Node::Node(): data(-1), ptrNext(nullptr) {
}

Node::Node(float val, Node* next): data(val), ptrNext(next) {

}

void Node::setData(float _data){
	data = _data;
}

void Node::setNext(Node* next){
	ptrNext = next;
}

float Node::getData(){
	return data;
}
Node* Node::getNext(){
	return ptrNext;
}

void Node::print(){
	std::cout << data ;
}

Node::~Node() {

}

}
