// main.cpp

#include <iostream>
#include <string>
#include <list>
#include <string_view>
#include <stack>


std::vector<std::string> parseInput(std::string_view input) {
    std::vector<std::string> result;
    auto isWhitespace = [](char c) {
        return c == ' ';
    };
    std::string cur;
    for(char c : input) {
        if(!isWhitespace(c)) {
            cur += c;
        } else if(cur.size() > 0){
            result.push_back(cur);
            cur = std::string();
        }
    }
    if(cur.size() > 0) {
        result.push_back(cur);
    }
    return result;
}

enum class CmdType {
    BinaryOperator,
    Operand
};

enum class BinaryOperatorType : int {
    Add,
    Subtract,
    Multiply,
    Divide
};

using Cmd = std::pair<CmdType, int>;


Cmd createAddCmd() {
    return std::make_pair(CmdType::BinaryOperator, static_cast<int>(BinaryOperatorType::Add));
}

Cmd createSubtractCmd() {
    return std::make_pair(CmdType::BinaryOperator, static_cast<int>(BinaryOperatorType::Subtract));
}

Cmd createMultiplyCmd() {
    return std::make_pair(CmdType::BinaryOperator, static_cast<int>(BinaryOperatorType::Multiply));
}

Cmd createDivideCmd() {
    return std::make_pair(CmdType::BinaryOperator, static_cast<int>(BinaryOperatorType::Divide));
}

Cmd createOperandCmd(int value) {
    return std::make_pair(CmdType::Operand, value);
}

int evalBinaryOperator(BinaryOperatorType type, int left, int right) {
    int value;
    switch (type) {
        case BinaryOperatorType::Multiply:
            value = left * right;
            break;
        case BinaryOperatorType::Divide:
            value = left / right;
            break;
        case BinaryOperatorType::Add:
            value = left + right;
            break;
        case BinaryOperatorType::Subtract:
            value = left - right;
            break;
    }
    
    return value;
}

// A sequence of operand, operator, operand, operator, operand, ...
struct Expression {
    
    std::list<Cmd> cmds;
    using cmdsIter = std::list<Cmd>::iterator;
    
    void fold() {
        auto findBinaryOperator = [&](BinaryOperatorType type) {
            return std::find_if(cmds.begin(), cmds.end(), [type](const Cmd& cmd) {
                return cmd.first == CmdType::BinaryOperator && cmd.second == static_cast<int>(type);
            });
        };
        
        auto foldBinaryOperator = [&](cmdsIter it) {
            it--;
            int left = it->second;
            it = cmds.erase(it);
            
            it++;
            int right = it->second;
            it = cmds.erase(it);
            it--;
            
            BinaryOperatorType type = static_cast<BinaryOperatorType>(it->second);
            int value = evalBinaryOperator(type, left, right);
            *it = createOperandCmd(value);
        };
        
        cmdsIter it;
        
        while((it = findBinaryOperator(BinaryOperatorType::Multiply)) != cmds.end()) {
            foldBinaryOperator(it);
        }
        while((it = findBinaryOperator(BinaryOperatorType::Divide)) != cmds.end()) {
            foldBinaryOperator(it);
        }
        while((it = findBinaryOperator(BinaryOperatorType::Add)) != cmds.end()) {
            foldBinaryOperator(it);
        }
        while((it = findBinaryOperator(BinaryOperatorType::Subtract)) != cmds.end()) {
            foldBinaryOperator(it);
        }
        
    }
    
    int eval() {
        
        if(cmds.size() > 1) {
            fold();
        }
        return cmds.begin()->second;
    }
    
    void push(int value) {
        cmds.push_back(createOperandCmd(value));
    }
    
    void push(std::string thing) {
        if(thing == "*") {
            cmds.push_back(createMultiplyCmd());
        } else if(thing == "/") {
            cmds.push_back(createDivideCmd());
        } else if(thing == "+") {
            cmds.push_back(createAddCmd());
        } else if(thing == "-") {
            cmds.push_back(createSubtractCmd());
        } else {
            int value = std::stoi(thing);
            cmds.push_back(createOperandCmd(value));
        }
    }
    
};


int main() {
    
    std::string input;
    std::getline(std::cin, input);
    auto things = parseInput(input);
    
    std::stack<Expression> exprs;
    exprs.emplace();
    
    for(auto thing : things) {
        if(thing == "(") {
            exprs.emplace();
        }
        else if(thing == ")") {
            int value = exprs.top().eval();
            exprs.pop();
            exprs.top().push(value);
        } else {
            exprs.top().push(thing);
        }
    }
           
    std::cout << exprs.top().eval() << std::endl;
    
    return EXIT_SUCCESS;
}

