#include "AssignmentCommand.h"
#include <iostream>
#include <string>
#include "Utils.h"
#include "SymbolTable.h"
#include "ShuntingYard.h"
#include "Expression.h"
#include "DataWriterClient.h"

using namespace std;

void AssignmentCommand::execute(vector <string>& arrCommands)
{
    string command = *arrCommands.begin();
    arrCommands.erase(arrCommands.begin());
    size_t equalSignPos = command.find_first_of('=');
    if (equalSignPos == string::npos){
        cout << "Assignment command "  << MESSAGE_SYNTAX_ERROR << endl;
        return;
    }
    string name = Utils::trim(command.substr(0, equalSignPos - 1));
    string expressionStr = Utils::trim(command.substr(equalSignPos + 1));
    Expression* expression = ShuntingYard::createExpression(expressionStr);
    if (expression != NULL)
    {
        VariableInfo* existingInfo = SymbolTable::getInstance()->getInfo(name);
        if (existingInfo == NULL)
        {
            cout << "Bad variable name " << name << endl;
            return;
        }
        existingInfo->value = expression->calculate();
        delete expression;
        // update the simulator
        if (existingInfo->bindName.size() > 0)
        {
            string updateCommand = "set " + existingInfo->bindName + " " + std::to_string(existingInfo->value) + "\r\n";
            DataWriterClient::getInstance()->setCommand(updateCommand);
        }
    }
}
