//  expression_tree_builder.cpp

#include "expression_tree_builder.hpp"

#include "expression_tree_node.hpp"

ExpressionTreeBuilder::ExpressionTreeBuilder() {
    _stack.emplace();
}

void ExpressionTreeBuilder::openParenthesis() {
    _stack.emplace();
}

void ExpressionTreeBuilder::closeParenthesis() {
    _Builder top = _stack.top();
    _stack.pop();
    _stack.top().addOperand(top.root);
}

void ExpressionTreeBuilder::modulo() {
    _stack.top().addOperator(new ModNode());
}

void ExpressionTreeBuilder::multiply() {
    _stack.top().addOperator(new MulNode());
}

void ExpressionTreeBuilder::divide() {
    _stack.top().addOperator(new DivNode());
}

void ExpressionTreeBuilder::add() {
    _stack.top().addOperator(new AddNode());
}

void ExpressionTreeBuilder::subtract() {
    _stack.top().addOperator(new SubNode());
}

void ExpressionTreeBuilder::number(int value) {
    _stack.top().addOperand(new NumberNode(value));
}

ExpressionTreeBuilder::_Builder::_Builder() : root(nullptr), lastOperator(nullptr) {}

void ExpressionTreeBuilder::_Builder::addOperator(OperatorNode* node) {
    
    IExpressionTreeNode* _root = root;
    size_t operandCount = node->leftOperandCount();
    if(operands.size() >= operandCount) {
        
        // set all previous operands as our left operands
        for(size_t i = 0; i < operandCount; i++) {
            node->setLeftOperand(operandCount - i - 1, operands.top());
            operands.pop();
        }
        
        if(lastOperator != nullptr && lastOperator->rightOperandCount() > 0) {
            // handle the dispute over our leftmost operand/ their rightmost operand
            if(node->precedence() > lastOperator->precedence()) {
                // we become their rightmost node
                size_t index = lastOperator->rightOperandCount() - 1;
                lastOperator->setRightOperand(index, node);
            } else {
                // they become our leftmost node
                size_t index = node->leftOperandCount() - 1;
                node->setLeftOperand(index, lastOperator);
                root = node;
            }
        } else {
            root = node;
        }
        
        lastOperator = nullptr;
        if(node->rightOperandCount() > 0) {
            lastOperator = node;
        }
    } else {
        throw std::invalid_argument("Invalid operator. There are too few left operands.");
    }
    
    
}

void ExpressionTreeBuilder::_Builder::addOperand(IExpressionTreeNode* node) {
    operands.push(node);
    if(root == nullptr) {
        root = node;
    } else if(lastOperator != nullptr && lastOperator->rightOperandCount() >= operands.size()) {
            lastOperator->setRightOperand(operands.size() - 1, node);
    }
}
    
ExpressionTree ExpressionTreeBuilder::getExpressionTree() const {
    ExpressionTree tree(_stack.top().root);
    return tree;
}
