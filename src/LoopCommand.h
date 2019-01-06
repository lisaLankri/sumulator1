#ifndef PROJECT_WHILECOMMAND_H
#define PROJECT_WHILECOMMAND_H

#include "ICommand.h"
#include "ConditionParser.h"

class LoopCommand : public ICommand {
public:
    LoopCommand();
    ~LoopCommand();
    virtual void execute(vector <string>& arrCommands);

protected:
    bool pepareCommand(vector <string>& arrCommands);

    vector<string> commandsParams;
    ConditionParser condition;
};

#endif //PROJECT_WHILECOMMAND_H
