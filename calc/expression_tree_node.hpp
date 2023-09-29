//  expression_tree_node.hpp

#ifndef expression_tree_node_hpp
#define expression_tree_node_hpp

#include <cstddef>

class IExpressionTreeVisitor;

class IExpressionTreeNode {
public:
    virtual ~IExpressionTreeNode();
    
    virtual void accept(IExpressionTreeVisitor* visitor) = 0;
};

class OperatorNode : public IExpressionTreeNode {
public:
    virtual size_t leftOperandCount() const = 0;
    virtual IExpressionTreeNode* getLeftOperand(size_t index) const = 0;
    virtual void setLeftOperand(size_t index, IExpressionTreeNode* node) = 0;
    
    virtual size_t rightOperandCount() const = 0;
    virtual IExpressionTreeNode* getRightOperand(size_t index) const = 0;
    virtual void setRightOperand(size_t index, IExpressionTreeNode* node) = 0;
    
    virtual int precedence() const = 0;
};

class BinaryInfixNode : public OperatorNode {
public:
    size_t leftOperandCount() const override;
    IExpressionTreeNode* getLeftOperand(size_t index) const override;
    void setLeftOperand(size_t index, IExpressionTreeNode* node) override;
    
    size_t rightOperandCount() const override;
    IExpressionTreeNode* getRightOperand(size_t index) const override;
    void setRightOperand(size_t index, IExpressionTreeNode* node) override;
    
    
private:
    IExpressionTreeNode* _left;
    IExpressionTreeNode* _right;
};

struct NumberNode : public IExpressionTreeNode {
    NumberNode(int value);
    int value;
    void accept(IExpressionTreeVisitor* visitor) override;
};

struct MulNode : public BinaryInfixNode {
    void accept(IExpressionTreeVisitor* visitor) override;
    int precedence() const override;
};
struct DivNode : public BinaryInfixNode {
    void accept(IExpressionTreeVisitor* visitor) override;
    int precedence() const override;
};
struct AddNode : public BinaryInfixNode {
    void accept(IExpressionTreeVisitor* visitor) override;
    int precedence() const override;
};
struct SubNode : public BinaryInfixNode {
    void accept(IExpressionTreeVisitor* visitor) override;
    int precedence() const override;
};
struct ModNode : public BinaryInfixNode {
    void accept(IExpressionTreeVisitor* visitor) override;
    int precedence() const override;
};




#endif /* expression_tree_node_hpp */
