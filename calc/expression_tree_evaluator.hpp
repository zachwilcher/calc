//  expression_tree_evaluator.hpp

#ifndef expression_tree_evaluator_hpp
#define expression_tree_evaluator_hpp

#include "expression_tree_visitor.hpp"
#include "expression_tree.hpp"

class ExpressionTreeEvaluator : public ExpressionTreeVisitor {
public:
    ExpressionTreeEvaluator(IExpressionTreeNode*);
    
    int getValue() const;
    
    virtual void visitNumberNode(NumberNode* node) override;
    virtual void visitMulNode(MulNode* node) override;
    virtual void visitDivNode(DivNode* node) override;
    virtual void visitAddNode(AddNode* node) override;
    virtual void visitSubNode(SubNode* node) override;
    virtual void visitModNode(ModNode* node) override;
private:
    int _value;
};

#endif /* expression_tree_evaluator_hpp */
