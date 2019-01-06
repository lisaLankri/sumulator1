#ifndef PROJECT_PRINTCOMMAND_H
#define PROJECT_PRINTCOMMAND_H

#include "ICommand.h"

class PrintCommand : public ICommand {
public:
    virtual void execute(vector <string>& arrCommands);
};


#endif //PROJECT_PRINTCOMMAND_H
