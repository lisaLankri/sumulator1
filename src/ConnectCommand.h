#ifndef PROJECT_CONNECTCOMMAND_H
#define PROJECT_CONNECTCOMMAND_H

#include "ICommand.h"

class ConnectCommand : public ICommand {
public:
    virtual void execute(vector <string>& arrCommands);
};


#endif //PROJECT_CONNECTCOMMAND_H
