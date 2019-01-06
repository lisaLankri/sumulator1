#include "ICommand.h"

#include <string>

using namespace std;

class OpenServerCommand : public ICommand{
public:
    OpenServerCommand();
    void execute(vector <string>& arrCommands);
};