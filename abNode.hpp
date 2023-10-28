#ifndef ABNODE_HPP_
#define ABNODE_HPP_

#include <iostream>

namespace eda {

class ABNode {
private:
	ABNode* ptrLeft;
	std::string data;
	ABNode* ptrRight;
	int size;
public:
	ABNode();
	ABNode(std::string val);
	void setLeft(ABNode* node);
	void setRight(ABNode* node);
	void setData(std::string val);
	void setSize(int s);
	ABNode* getLeft();
	ABNode* getRight();
	std::string getData();
	int getSize();
	virtual ~ABNode();
};

} 
#endif 
