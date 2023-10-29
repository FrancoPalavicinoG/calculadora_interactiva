#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include "node.hpp"
#include "stack.hpp"
#include "calculator.hpp"
#include "treeNode.hpp"
#include "tree.hpp"

using namespace eda;
using namespace std;

namespace calculator {

Calculator::Calculator(){}

int Calculator::prec(char c){
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1; 
}

string Calculator::infixToPostfix(string s) {
    aux = "";
    Stack st;
    string result;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == ' ') {
            continue;  // Ignora los espacios en blanco
        }
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            string token;
            while (i < s.length() && ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))) {
                token += s[i];
                i++;
            }
            i--; // Retrocede para evitar saltarse el siguiente carácter
            if (var.find(token) != var.end()) {
                result += to_string(var[token]); // Reemplaza por el valor numérico
                aux += token;
            } else {
                result += token; // Mantén la variable si no está definida
                aux += token;
            }
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.isEmpty() && st.top()->getData() != '(') {
                result += ' ';
                aux += ' ';
                result += st.top()->getData();
                aux += st.top()->getData();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.isEmpty() && prec(c) <= prec(st.top()->getData())) {
                result += ' ';
                aux += ' ';
                result += st.top()->getData();
                aux += st.top()->getData();
                st.pop();
            }
            result += ' ';
            aux += ' ';
            st.push(c);
        }
    }
    while (!st.isEmpty()) {
        result += ' ';
        aux += ' ';
        result += st.top()->getData();
        aux += st.top()->getData();
        st.pop();
    }
    //cout << result << endl;
    //cout << aux << endl;
    return result;
}

float Calculator::postfix(string s) {
    Stack p;
    istringstream ss(s);
    string token;
    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
            float second = p.top()->getData();
            p.pop();
            float first = p.top()->getData();
            p.pop();
            float result = 0;

            if (token == "+") {
                result = first + second;
            } else if (token == "-") {
                result = first - second;
            } else if (token == "*") {
                result = first * second;
            } else if (token == "/") {
                if (second == 0){
                    cout << "Error: Divide by zero" << endl;
                    ans = 0;
                }else {
                    result = first / second;
                }
            } else if (token == "^") {
                result = pow(first, second);
            }
            p.push(result);

        } else {            
            if (token == "ans"){
                p.push(ans); 
            }
            else{
                float num = stof(token);
                p.push(num);
            }
        }
    }
    ans = p.top()->getData();
    return ans;
}

void Calculator::setVar(string s) {
    istringstream ss(s);
    string name, equal, value;
    if (ss >> name >> equal >> value) {
        if (equal == "=") {
            int val;
            if (value == "ans"){
                var[name] = ans;  
            }
            else if (istringstream(value) >> val) {
                var[name] = val;  // Agrega la variable al mapa local
            }
        }
    }
    /*
    cout << "Variables definidas:" << std::endl;
    for (const auto& pair : var) {
        std::cout << pair.first << " = " << pair.second << std::endl;
    }
    */
}
 
TreeNode* Calculator::createTree() {
        stack<TreeNode*> p;
        istringstream ss(aux);
        string token;
        while (ss >> token) {
            if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
                TreeNode n; 
                TreeNode* new_node = n.setter(token); 
                new_node->ptrRight = p.top();
                p.pop();
                new_node->ptrLeft = p.top();
                p.pop();
                p.push(new_node);
            }else {
                TreeNode n; 
                TreeNode* new_node = n.setter(token); 
                p.push(new_node);
            }
        }
        return p.top();
    }

void Calculator::interfaz() {
    cout << "\n";
    cout << "======= CALCULADORA INTERACTIVA =======" << endl;
    cout << "\n";
    string comando;
    while (true){
        cout << "$ ";
        getline(cin, comando);
        if (comando == "FIN" || comando == "fin" || comando == "Fin") {
            break;  
        } else {
            char c = comando[2];
            if (c == '='){
                setVar(comando);
            }else if (comando == "tree"){
                Tree t;
                t.root = createTree();
                t.traverse();
            }else{
                string postfixExpression = infixToPostfix(comando);
                float result = postfix(postfixExpression);
                cout << "ans = " << result << endl;
            }
        }
    }
}

}

int main() {
    calculator::Calculator calc;
    calc.interfaz();
    return 0;
}

