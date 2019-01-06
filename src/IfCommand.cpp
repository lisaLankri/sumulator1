#include "IfCommand.h"
#include <iostream>
#include "ConditionParser.h"
#include "Utils.h"
#include "Parser.h"

using namespace std;

void IfCommand::execute(vector <string>& arrCommands)
{
    if (pepareCommand(arrCommands))
    {
        // run the if
        if(condition.isConditionMet())
        {
            Parser parser;
            for (vector<string>::iterator it = commandsParams.begin(); it != commandsParams.end(); ++it)
            {
                vector<string> params;
                params.push_back(*it);
                parser.run(params);
            }
        }
    }
}
