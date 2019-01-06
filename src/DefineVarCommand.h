#ifndef PROJECT_DEFINEVARCOMMAND_H
#define PROJECT_DEFINEVARCOMMAND_H

#include "ICommand.h"

class DefineVarCommand : public ICommand {
public:
    virtual void execute(vector <string>& arrCommands);
};


#endif //PROJECT_DEFINEVARCOMMAND_H
