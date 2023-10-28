#ifndef Tree_HPP_
#define Tree_HPP_

#include "treeNode.hpp"
#include "treeNode.hpp"
#include <iostream>

namespace eda {

class Tree {
private:
	TreeNode* root;
public:
	Tree();
	void setRoot(TreeNode* root);
	TreeNode* getRoot();
	void insert_rec(std::string val, TreeNode* node);
	void insert(std::string val);
	void traverse_rec(eda::TreeNode* node, int level);
	void traverse();
	virtual ~Tree();
};

} 

#endif