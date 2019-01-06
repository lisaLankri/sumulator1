#include "ConditionParser.h"
#include "SymbolTable.h"
#include <iostream>

ConditionParser::ConditionParser(string _varName, string _operation, string _value) :
        varName(_varName), operation(_operation), value(_value)
{
}

void ConditionParser::setParams(string _varName, string _operation, string _value)
{
    varName = _varName;
    operation = _operation;
    value = _value;
}

bool ConditionParser::isConditionMet()
{
    VariableInfo* existingInfo = SymbolTable::getInstance()->getInfo(varName);
    if (existingInfo == NULL)
    {
        return false;
    }
    double dValue = std::stod(value);
    if (operation == "!=")
    {
        return existingInfo->value != dValue;
    }
    if (operation == "==")
    {
        return existingInfo->value == dValue;
    }
    if (operation == ">=")
    {
        return existingInfo->value >= dValue;
    }
    if (operation == "<=")
    {
        return existingInfo->value <= dValue;
    }
    if (operation == ">")
    {
        return existingInfo->value > dValue;
    }
    if (operation == "<")
    {
        return existingInfo->value < dValue;
    }
    return false; // should not happen
}
