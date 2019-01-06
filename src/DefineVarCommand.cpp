#include "DefineVarCommand.h"
#include <iostream>
#include "Utils.h"
#include "SymbolTable.h"

using namespace std;

void DefineVarCommand::execute(vector <string>& arrCommands)
{
    vector<string> arrParams = Utils::splitToWords(*arrCommands.begin());
    if (arrParams.size() < 4){
        cout << "DefineVarCommand1 " << MESSAGE_SYNTAX_ERROR << endl;
    }
    arrCommands.erase(arrCommands.begin());
    vector<string>::iterator it = arrParams.begin();
    ++it; // skip the command name
    string name = *it;
    ++it;
    if (*it != "="){
        cout << "DefineVarCommand2 " << MESSAGE_SYNTAX_ERROR << endl;
        return;
    }
    ++it;
    if (*it != "bind") {
        // assign value to existing variable
        string value = *it;
        VariableInfo* valueInfo = SymbolTable::getInstance()->getInfo(value);
        if (valueInfo != NULL)
            SymbolTable::getInstance()->addVariableInfo(name, valueInfo->value);
        else
            SymbolTable::getInstance()->addVariableInfo(name, std::stod(value));
    } else{
        if (arrParams.size() < 5){
            cout << "DefineVarCommand3 " << MESSAGE_SYNTAX_ERROR << endl;
            return;;
        }
        ++it;
        string bindName = *it;
        if ((bindName.size() > 0) && (bindName[0] == '\"'))
            bindName = bindName.substr(1);
        if ((bindName.size() > 0) && (bindName[bindName.size() - 1] == '\"'))
            bindName = bindName.substr(0, bindName.size() - 1);
        if ((bindName.size() > 0) && (bindName[0] == '/'))
            bindName = bindName.substr(1);
        SymbolTable::getInstance()->addVariableInfo(name, bindName);
    }
}
