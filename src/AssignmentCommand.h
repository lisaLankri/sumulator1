#ifndef PROJECT_ASSIGNMENTCOMMAND_H
#define PROJECT_ASSIGNMENTCOMMAND_H

#include "ICommand.h"

class AssignmentCommand : public ICommand {
public:
    virtual void execute(vector <string>& arrCommands);
};


#endif //PROJECT_ASSIGNMENTCOMMAND_H
