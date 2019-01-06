#ifndef PROJECT_COMMANDSCREATOR_H
#define PROJECT_COMMANDSCREATOR_H

#include <string>
#include <map>

using namespace std;

#define OPEN_DATA_SERVER_COMMAND    "openDataServer"
#define CONNECT_COMMAND             "connect"
#define VAR_COMMAND                 "var"
#define ASSIGNMENT_COMMAND           "assignment"
#define PRINT_COMMAND           "print"
#define SLEEP_COMMAND           "sleep"
#define WHILE_COMMAND           "while"
#define IF_COMMAND           "if"

class ICommand;

class CommandsCreator {
public:
    ~CommandsCreator();
    ICommand* createCommand(string& commandName);
    static CommandsCreator* getInstance();

private:
    CommandsCreator();
    map<string, ICommand*> commands;
};


#endif //PROJECT_COMMANDSCREATOR_H
