#ifndef AB_HPP_
#define AB_HPP_

#include "abNode.hpp"

namespace trees {

class AB {
private:
	ABNode* root;
public:
	AB();
	void insert_rec(int val, ABNode* node);
	void insert(int val);
	void traverse_rec(ABNode* node, int level);
	void traverse();
	virtual ~AB();
};

} 

#endif