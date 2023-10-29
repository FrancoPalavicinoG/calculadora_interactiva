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
    void setVar(std::string s);
    void interfaz();
    eda::TreeNode* createTree();
    void printVar(const std::string s);
	Calculator();
    int prec(char c);
	std::string infixToPostfix(std::string s);
    float postfix(std::string s);
	};
}

#endif