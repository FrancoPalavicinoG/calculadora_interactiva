#ifndef CALC_HPP_
#define CALC_HPP_

#include <iostream>
#include <map>
#include "treeNode.hpp"

namespace calculator {

class Calculator{
public:
    std::string aux;
    float ans = 0;
    std::map <std::string, int> var;
    Calculator();
    int prec(char c);
    std::string infixToPostfix(std::string s);
    float postfix(std::string s);
    void setVar(std::string s);
    eda::TreeNode* createTree();
    void interfaz();
	};
}

#endif