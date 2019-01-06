#include "Variable.h"
#include "SymbolTable.h"

Variable::Variable(string _variableName) : variableName(_variableName) {}

double Variable::calculate()
{
    VariableInfo* varInfo = SymbolTable::getInstance()->getInfo(variableName);
    if (varInfo != NULL)
        return varInfo->value;
    return 0;// should not happen
}
