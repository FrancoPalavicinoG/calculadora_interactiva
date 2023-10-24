#ifndef ABNODE_HPP_
#define ABNODE_HPP_

namespace trees {

class ABNode {
private:
	ABNode* ptrLeft;
	int data;
	ABNode* ptrRight;
	int size;
public:
	ABNode();
	ABNode(int val);
	void setLeft(ABNode* node);
	void setRight(ABNode* node);
	void setData(int val);
	void setSize(int s);
	ABNode* getLeft();
	ABNode* getRight();
	int getData();
	int getSize();
	virtual ~ABNode();
};

} 
#endif 
