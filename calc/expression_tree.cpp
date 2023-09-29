//  expression_tree.cpp

#include "expression_tree.hpp"
#include "expression_tree_evaluator.hpp"
ExpressionTree::ExpressionTree(IExpressionTreeNode* root) : _root(root) {}
ExpressionTree::~ExpressionTree() = default;

int ExpressionTree::evaluate() const {
    ExpressionTreeEvaluator evaluator(_root);
    return evaluator.getValue();
}

