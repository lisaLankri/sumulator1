#ifndef PROJECT_EXPRESSION_H
#define PROJECT_EXPRESSION_H


class Expression {
public:
    virtual ~Expression() {}
    virtual double calculate() = 0;
};


#endif //PROJECT_EXPRESSION_H
