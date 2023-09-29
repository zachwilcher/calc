//  calculator.cpp

#include "calculator.hpp"

#include <sstream>

#include "expression_tree_builder.hpp"
#include "expression_tree_evaluator.hpp"

int Calculator::evaluateInfix(const std::string& input) const {
    std::istringstream stream(input);
    std::string token;
    
    ExpressionTreeBuilder builder;
    
    while(stream.good()) {
        stream >> token;
        
        if(token == "(") {
            builder.openParenthesis();
        }
        else if(token == ")") {
            builder.closeParenthesis();
        }
        else if(token == "%") {
            builder.modulo();
        }
        else if(token == "*") {
            builder.multiply();
        }
        else if(token == "/") {
            builder.divide();
        }
        else if(token == "+") {
            builder.add();
        }
        else if(token == "-") {
            builder.subtract();
        }
        else {
            int value;
            try {
                value = std::stoi(token);
            } catch(const std::invalid_argument& e) {
                throw std::invalid_argument("Unknown token!");
            }
            builder.number(value);
        }
    }
    
    ExpressionTree expressionTree = builder.getExpressionTree();
    
    return expressionTree.evaluate();
}
