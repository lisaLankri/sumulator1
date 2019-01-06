#include "PrintCommand.h"
#include <iostream>
#include "Utils.h"
#include "SymbolTable.h"

using namespace std;

void PrintCommand::execute(vector <string>& arrCommands)
{
    vector<string> arrParams = Utils::splitToWords(*arrCommands.begin());
    arrCommands.erase(arrCommands.begin());
    if (arrParams.size() != 2){
        cout << "PrintCommand " << MESSAGE_SYNTAX_ERROR << endl;
    }
    else {
        vector<string>::iterator it = arrParams.begin();
        ++it; // skip the command name
        string value = *it;
        VariableInfo* existingInfo = SymbolTable::getInstance()->getInfo(value);
        if (existingInfo == NULL)
        {
            cout << value << endl;
        } else {
            cout << existingInfo->value << endl;
        }
    }
}
