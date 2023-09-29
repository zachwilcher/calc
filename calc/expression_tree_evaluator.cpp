//  expression_tree_evaluator.cpp

#include "expression_tree_evaluator.hpp"
#include "expression_tree_node.hpp"

ExpressionTreeEvaluator::ExpressionTreeEvaluator(IExpressionTreeNode* root) :
    _value(0)
{
    root->accept(this);
}

int ExpressionTreeEvaluator::getValue() const {
    return _value;
}

void ExpressionTreeEvaluator::visitNumberNode(NumberNode* node) {
    _value = node->value;
}
void ExpressionTreeEvaluator::visitMulNode(MulNode* node) {
    ExpressionTreeEvaluator left(node->getLeftOperand(0));
    ExpressionTreeEvaluator right(node->getRightOperand(0));
    _value = left._value * right._value;
}
void ExpressionTreeEvaluator::visitDivNode(DivNode* node) {
    ExpressionTreeEvaluator left(node->getLeftOperand(0));
    ExpressionTreeEvaluator right(node->getRightOperand(0));
    _value = left._value / right._value;
}
void ExpressionTreeEvaluator::visitAddNode(AddNode* node) {
    ExpressionTreeEvaluator left(node->getLeftOperand(0));
    ExpressionTreeEvaluator right(node->getRightOperand(0));
    _value = left._value + right._value;
}
void ExpressionTreeEvaluator::visitSubNode(SubNode* node) {
    ExpressionTreeEvaluator left(node->getLeftOperand(0));
    ExpressionTreeEvaluator right(node->getRightOperand(0));
    _value = left._value - right._value;
}
void ExpressionTreeEvaluator::visitModNode(ModNode* node) {
    ExpressionTreeEvaluator left(node->getLeftOperand(0));
    ExpressionTreeEvaluator right(node->getRightOperand(0));
    _value = left._value % right._value;
}
