#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <vector>
#include <string>

using namespace std;
#define MESSAGE_SYNTAX_ERROR "Incorrect syntax"

class ICommand{
public:
    virtual ~ICommand() {}
    virtual void execute(vector <string>& arrCommands) = 0;
};

#endif
