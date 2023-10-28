#ifndef NODE_HPP_
#define NODE_HPP_

namespace eda {

class Node {
private:
	float data;
	Node* ptrNext;
public:
	Node();
	Node(float _data, Node* next = nullptr);
	void setData(float _data);
	void setNext(Node* _next);
	float getData();
	Node* getNext();
	void print();
	virtual ~Node();
};

} 

#endif