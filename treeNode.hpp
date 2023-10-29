#ifndef TREE_NODE_HPP_
#define TREE_NODE_HPP_

#include <string>
#include <iostream>

namespace eda {

class TreeNode {
public:
    std::string data;
    TreeNode* ptrNext;
    TreeNode* ptrLeft;
    TreeNode* ptrRight;
    int size;


    TreeNode();
    TreeNode(std::string val);
    TreeNode* create_node(std::string s);
    void setData(std::string _data);
    void setNext(TreeNode* _next);
    void setLeft(TreeNode* left);
    void setRight(TreeNode* right);
    void setSize(int s);
    std::string getData();
    TreeNode* getNext();
    TreeNode* getLeft();
    TreeNode* getRight();
    int getSize();
    void print();
    virtual ~TreeNode();
};

}

#endif
