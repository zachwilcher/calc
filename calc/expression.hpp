//  expression.hpp

#ifndef expression_hpp
#define expression_hpp

class IExpression {
public:
    virtual ~IExpression();
    virtual int evaluate() const = 0;
};


#endif /* expression_hpp */
