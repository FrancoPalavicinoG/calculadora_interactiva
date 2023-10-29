#ifndef TREE_NODE_HPP_
#define TREE_NODE_HPP_

#include <string>
#include <iostream>

namespace eda {

class TreeNode {
public:
    std::string data;
    TreeNode* ptrLeft;
    TreeNode* ptrRight;


    TreeNode();
    TreeNode(std::string val);
    TreeNode* setter(std::string s);
    void setData(std::string _data);
    void setLeft(TreeNode* left);
    void setRight(TreeNode* right);
    std::string getData();
    TreeNode* getLeft();
    TreeNode* getRight();
    virtual ~TreeNode();
};

}

#endif
