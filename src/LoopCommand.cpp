#include "LoopCommand.h"
#include <iostream>
#include "ConditionParser.h"
#include "Utils.h"
#include "Parser.h"

using namespace std;

LoopCommand::LoopCommand() {}

LoopCommand::~LoopCommand()
{
}

bool LoopCommand::pepareCommand(vector <string>& arrCommands)
{
    vector<string> arrParams = Utils::splitToWords(*arrCommands.begin());
    arrCommands.erase(arrCommands.begin());
    if (arrParams.size() != 5){
        cout << "WhileCommand1 " << MESSAGE_SYNTAX_ERROR << endl;
        return false;
    }
    else {
        // parse the while command
        vector<string>::iterator it = arrParams.begin();
        ++it; // skip the command name
        string varName = *it;
        ++it;
        string operation = *it;
        ++it;
        string value = *it;
        ++it;
        if (*it != "{"){
            cout << "WhileCommand2 " << MESSAGE_SYNTAX_ERROR << endl;
            return false;
        }
        condition.setParams(varName, operation, value);
        // collect the inner commands

        vector<string>::iterator commandsIter = arrCommands.begin();
        int commandsToDelete = 0;
        while(commandsIter != arrCommands.end()) {
            commandsToDelete++;
            if (*commandsIter != "}")
                commandsParams.push_back(*commandsIter);
            else
                break;
            ++commandsIter;
        }
        while (commandsToDelete > 0){
            arrCommands.erase(arrCommands.begin());
            commandsToDelete--;
        }
    }
    return true;
}

void LoopCommand::execute(vector <string>& arrCommands)
{
    if (pepareCommand(arrCommands))
    {
        Parser parser;
        // run the loop
        while(condition.isConditionMet())
        {
            for (vector<string>::iterator it = commandsParams.begin(); it != commandsParams.end(); ++it)
            {
                vector<string> params;
                params.push_back(*it);
                parser.run(params);
            }
        }
    }
}
