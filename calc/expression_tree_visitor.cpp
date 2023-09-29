//
//  expression_tree_visitor.cpp
//  calc
//
//  Created by Zach Wilcher on 9/28/23.
//

#include "expression_tree_visitor.hpp"

IExpressionTreeVisitor::~IExpressionTreeVisitor() = default;

ExpressionTreeVisitor::~ExpressionTreeVisitor() = default;
void ExpressionTreeVisitor::visitNumberNode(NumberNode* node) {}
void ExpressionTreeVisitor::visitMulNode(MulNode* node) {}
void ExpressionTreeVisitor::visitDivNode(DivNode* node) {}
void ExpressionTreeVisitor::visitAddNode(AddNode* node) {}
void ExpressionTreeVisitor::visitSubNode(SubNode* node) {}
void ExpressionTreeVisitor::visitModNode(ModNode* node) {}
