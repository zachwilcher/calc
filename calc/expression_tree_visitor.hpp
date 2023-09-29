//  expression_tree_visitor.hpp

#ifndef expression_tree_visitor_hpp
#define expression_tree_visitor_hpp

class NumberNode;
class MulNode;
class DivNode;
class AddNode;
class SubNode;
class ModNode;


class IExpressionTreeVisitor {
public:
    virtual ~IExpressionTreeVisitor();
    
    virtual void visitNumberNode(NumberNode* node) = 0;
    virtual void visitMulNode(MulNode* node) = 0;
    virtual void visitDivNode(DivNode* node) = 0;
    virtual void visitAddNode(AddNode* node) = 0;
    virtual void visitSubNode(SubNode* node) = 0;
    virtual void visitModNode(ModNode* node) = 0;
};

class ExpressionTreeVisitor : public IExpressionTreeVisitor {
public:
    virtual ~ExpressionTreeVisitor();
    virtual void visitNumberNode(NumberNode* node) override;
    virtual void visitMulNode(MulNode* node) override;
    virtual void visitDivNode(DivNode* node) override;
    virtual void visitAddNode(AddNode* node) override;
    virtual void visitSubNode(SubNode* node) override;
    virtual void visitModNode(ModNode* node) override;
};

#endif /* expression_tree_visitor_hpp */
