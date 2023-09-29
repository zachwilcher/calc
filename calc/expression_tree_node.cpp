//  expression_tree_node.cpp

#include "expression_tree_node.hpp"

#include "expression_tree_visitor.hpp"

#include <stdexcept>
IExpressionTreeNode::~IExpressionTreeNode() = default;

size_t BinaryInfixNode::leftOperandCount() const {
    return 1;
}
IExpressionTreeNode* BinaryInfixNode::getLeftOperand(size_t index) const {
    if(index < leftOperandCount()) {
        return _left;
    } else {
        throw std::out_of_range("Binary infix has only 1 left operand");
    }
}
void BinaryInfixNode::setLeftOperand(size_t index, IExpressionTreeNode* node) {
    if(index < leftOperandCount()) {
        _left = node;
    } else {
        throw std::out_of_range("Binary infix has only 1 left operand");
    }
}
    
size_t BinaryInfixNode::rightOperandCount() const {
    return 1;
}
IExpressionTreeNode* BinaryInfixNode::getRightOperand(size_t index) const {
    if(index < rightOperandCount()) {
        return _right;
    } else {
        throw std::out_of_range("Binary infix has only 1 right operand");
    }
    
}
void BinaryInfixNode::setRightOperand(size_t index, IExpressionTreeNode* node) {
    if(index < rightOperandCount()) {
        _right = node;
    } else {
        throw std::out_of_range("Binary infix has only 1 right operand");
    }
}

NumberNode::NumberNode(int value) : value(value) {
}
void NumberNode::accept(IExpressionTreeVisitor* visitor) {
    visitor->visitNumberNode(this);
}
void MulNode::accept(IExpressionTreeVisitor* visitor) {
    visitor->visitMulNode(this);
}
int MulNode::precedence() const {
    return 4;
}
void DivNode::accept(IExpressionTreeVisitor* visitor) {
    visitor->visitDivNode(this);
}
int DivNode::precedence() const {
    return 3;
}
void AddNode::accept(IExpressionTreeVisitor* visitor) {
    visitor->visitAddNode(this);
}
int AddNode::precedence() const {
    return 1;
}
void SubNode::accept(IExpressionTreeVisitor* visitor) {
    visitor->visitSubNode(this);
}
int SubNode::precedence() const {
    return 1;
}
void ModNode::accept(IExpressionTreeVisitor* visitor) {
    visitor->visitModNode(this);
}
int ModNode::precedence() const {
    return 4;
}
