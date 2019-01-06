#ifndef PROJECT_IFCOMMAND_H
#define PROJECT_IFCOMMAND_H

#include "LoopCommand.h"

class IfCommand : public LoopCommand {
public:
    virtual void execute(vector <string>& arrCommands);
};


#endif //PROJECT_IFCOMMAND_H
