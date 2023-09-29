//  expression_tree_builder.hpp

#ifndef expression_tree_builder_hpp
#define expression_tree_builder_hpp

#include "expression_tree.hpp"

#include <stack>

class IExpressionTreeNode;
class OperatorNode;


class ExpressionTreeBuilder {
public:
    ExpressionTreeBuilder();
    void openParenthesis();
    void closeParenthesis();
    void modulo();
    void multiply();
    void divide();
    void add();
    void subtract();
    void number(int value);
    
    ExpressionTree getExpressionTree() const;
private:
    struct _Builder {
        _Builder();
        void addOperator(OperatorNode*);
        void addOperand(IExpressionTreeNode*);
    
        std::stack<IExpressionTreeNode*> operands;
        OperatorNode* lastOperator;
        IExpressionTreeNode* root;
    };
    std::stack<_Builder> _stack;
};

#endif /* expression_tree_builder_hpp */
