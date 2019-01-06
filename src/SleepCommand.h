#ifndef PROJECT_SLEEPCOMMAND_H
#define PROJECT_SLEEPCOMMAND_H

#include "ICommand.h"

class SleepCommand : public ICommand {
public:
    virtual void execute(vector <string>& arrCommands);
};


#endif //PROJECT_SLEEPCOMMAND_H
