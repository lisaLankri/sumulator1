#ifndef PROJECT_NUMBER_H
#define PROJECT_NUMBER_H

#include "Expression.h"

class Number : public Expression {
public:
    Number(double);
    virtual double calculate() { return value;}

private:
    double value;
};


#endif //PROJECT_NUMBER_H
