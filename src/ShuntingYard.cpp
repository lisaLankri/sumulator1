#include "ShuntingYard.h"
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <stack>
#include <sstream>
#include <vector>
#include "Expression.h"
#include "Number.h"
#include "Variable.h"
#include "Plus.h"
#include "Minus.h"
#include "Mul.h"
#include "Div.h"
#include "UnaryExpression.h"

using namespace std;

Expression* ShuntingYard::createExpression(string expression)
{
    // add spaces in order to be able to split the command to "words"
    string expressionWithSpaces;
    for (unsigned int i = 0; i < expression.size(); i++)
    {
        if (isOperator(expression[i]) || (expression[i] == '(') || (expression[i] == ')'))
        {
            expressionWithSpaces += " ";
            expressionWithSpaces += expression[i];
            expressionWithSpaces += " ";
        } else{
            expressionWithSpaces += expression[i];
        }
    }
    expression = expressionWithSpaces;
    istringstream iss(expression);
    vector<string> tokens;//store the tokens here
    while(iss)
    {
        string temp;
        iss >>temp;
        tokens.push_back(temp);
    }
    vector<string> outputList;//output vector
    stack<string> s;//main stack
    vector<Expression*> expressions;
    stack<Expression*> expressionsStack;//main stack

    for(unsigned int i = 0; i < tokens.size(); i++)  //read from right to left
    {
        string token = tokens[i];
        if (tokens[i].size() == 0)
            continue;
        if(IsNumber(tokens[i]))
        {
            outputList.push_back(tokens[i]);
            expressions.push_back(new Number(std::stod(tokens[i])));
        }
        else if (IsVariable(tokens[i]))
        {
            outputList.push_back(tokens[i]);
            expressions.push_back(new Variable(tokens[i]));
        }
        if(tokens[i] == "(")
        {
            s.push(tokens[i]);
        }
        if(tokens[i] == ")")
        {
            while(!s.empty() && s.top() != "(")
            {
                outputList.push_back(s.top());
                s.pop();
                expressions.push_back(expressionsStack.top());
                expressionsStack.pop();
            }
            s.pop();
        }
        if(isOperator(tokens[i]) == true)
        {
            while(!s.empty() && Priority(s.top()) >= Priority(tokens[i]))
            {
                outputList.push_back(s.top());
                s.pop();
                expressions.push_back(expressionsStack.top());
                expressionsStack.pop();
            }
            s.push(tokens[i]);
            if (tokens[i] == "+")
                expressionsStack.push(new Plus(NULL, NULL));
            else
            if (tokens[i] == "-")
                expressionsStack.push(new Minus(NULL, NULL));
            else
            if (tokens[i] == "*")
                expressionsStack.push(new Mul(NULL, NULL));
            else
            if (tokens[i] == "/")
                expressionsStack.push(new Div(NULL, NULL));
        }
    }
    //pop any remaining operators from the stack and insert to outputlist
    while(!s.empty())
    {
        outputList.push_back(s.top());
        s.pop();
    }
    while(!expressionsStack.empty())
    {
        expressions.push_back(expressionsStack.top());
        expressionsStack.pop();
    }

    /*for(unsigned int i = 0; i < outputList.size(); i++)
    {
        cout<<outputList[i] << " ";
    }
    cout << endl;*/
    // unify the all expressions to one expression
    stack<Expression*> finalExpressions;
    for(vector<Expression*>::iterator it = expressions.begin(); it != expressions.end(); ++it)
    {
        if ((dynamic_cast<Number*>(*it) != NULL) || (dynamic_cast<Variable*>(*it) != NULL)) {
            finalExpressions.push(*it);
        }
        else if (dynamic_cast<BinaryExpression*>(*it) != NULL) {
            Expression* right = finalExpressions.top();
            finalExpressions.pop();
            if (finalExpressions.size() > 0){
                Expression* left = finalExpressions.top();
                finalExpressions.pop();
                ((BinaryExpression*)(*it))->setLeft(left);
                ((BinaryExpression*)(*it))->setRight(right);
                finalExpressions.push(*it);
            }
            else { // need to replace the BinaryExpression by unary operator
                delete *it;
                finalExpressions.push(new UnaryExpression(right));
            }
        }
    }
    // debug
    //cout << "SIZE: " << finalExpressions.size() << endl;
    Expression* finalExpression = finalExpressions.top();
    //cout << "VAL: " << finalExpression->calculate() << endl;
    return finalExpression;
}

// return true if the symbol is a name of a variable
bool ShuntingYard::IsVariable(const string &symbol)
{
    for(unsigned int i = 0; i < symbol.size(); i++)
    {
        if (i == 0)
        {
            if (! isalpha(symbol[i]))
                return false;
        }
        else
        if(!isdigit(symbol[i]) && !isalpha(symbol[i]))
        {
            return false;
        }
    }
    return true;
}

// return true if the symbol is a number
bool ShuntingYard::IsNumber(const string &symbol)
{
    for(unsigned int i = 0; i < symbol.size(); i++)
    {
        if(!isdigit(symbol[i]) && (symbol[i] != '.'))
        {
            return false;
        }
    }
    return true;
}

int ShuntingYard::Priority(const string &c)
{
    if(c == "*" || c == "/")
    {
        return 2;
    }
    if(c== "+" || c == "-")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool ShuntingYard::isOperator(const string &c)
{
    return (c == "+" || c == "-" || c == "*" || c == "/");
}

bool ShuntingYard::isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
