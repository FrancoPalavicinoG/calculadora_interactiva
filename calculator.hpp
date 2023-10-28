#include <iostream>
#include <map>

namespace calculator {
	class Calculator{
	public:
        float ans = 0;
        std::map <std::string, int> var;
        void setVar(std::string s);
        void interfaz();
        void tree(std::string s);
        void printVar(const std::string s);
		Calculator();
        int prec(char c);
		std::string infixToPostfix(std::string s);
        float postfix(std::string s);
	};
}