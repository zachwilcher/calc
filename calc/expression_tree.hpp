//  expression_tree.hpp

#ifndef expression_tree_hpp
#define expression_tree_hpp

#include "expression.hpp"
#include "expression_tree_node.hpp"

class ExpressionTree : public IExpression {
public:
    virtual ~ExpressionTree();
    ExpressionTree(IExpressionTreeNode* root);
    int evaluate() const override;
private:
    IExpressionTreeNode* _root;
};



#endif /* expression_tree_hpp */
