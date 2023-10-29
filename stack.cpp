#include "stack.hpp"
#include <iostream>

namespace eda {

Stack::Stack():head(nullptr) {
}

void Stack::push(float val){
	Node* node = new Node(val);
	push(node);
}

void Stack::push(Node* node){
	node->setNext(head);
	head = node;
}

void Stack::pop(){
	if (!isEmpty()){
		Node* ptr = head;
		head = head->getNext();
		delete ptr;
	}
}

Node* Stack::top(){
	return head;
}

bool Stack::isEmpty(){
	return (head == nullptr);
}

void Stack::clear(){
	while (!isEmpty()){
		pop();
	}
}

Stack::~Stack() {
	clear();
}

}
