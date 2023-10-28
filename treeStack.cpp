#include "treeStack.hpp"
#include "ab.hpp"
#include <iostream>
#include <string>

namespace eda {

TreeStack::TreeStack():head(nullptr) {
	// TODO Auto-generated constructor stub

}

void TreeStack::push(std::string val){
	TreeNode* Treenode = new TreeNode(val);
	std::cout << "push: " << Treenode->getData() << std::endl;
	push(Treenode);
}

void TreeStack::push(Tree* tree) {
    // Agregar un árbol a la pila de árboles
    treeStack.push(tree);
}

void TreeStack::push(TreeNode* Treenode){
	Treenode->setNext(head);
	head = Treenode;
}

void TreeStack::pop(){
	if (!isEmpty()){
		TreeNode* ptr = head;
		head = head->getNext();
		delete ptr;
	}
}

TreeNode* TreeStack::top(){
	return head;
}

bool TreeStack::isEmpty(){
	return (head == nullptr);
}

void TreeStack::clear(){
	while (!isEmpty()){
		pop();
	}
}

TreeStack::~TreeStack() {
	//std::cout<<"destructor TreeStack"<<std::endl;
	clear();
}

}
