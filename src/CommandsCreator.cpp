#include "CommandsCreator.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "AssignmentCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "LoopCommand.h"
#include "IfCommand.h"

CommandsCreator::~CommandsCreator()
{
    // delete allocated memory
    for (map<string, ICommand*>::iterator it = commands.begin(); it != commands.end(); it++ )
    {
        delete it->second;
    }
}

CommandsCreator::CommandsCreator()
{
    commands[OPEN_DATA_SERVER_COMMAND] = new OpenServerCommand();
    commands[CONNECT_COMMAND] = new ConnectCommand();
    commands[VAR_COMMAND] = new DefineVarCommand();
    commands[ASSIGNMENT_COMMAND] = new AssignmentCommand();
    commands[PRINT_COMMAND] = new PrintCommand();
    commands[SLEEP_COMMAND] = new SleepCommand();
    commands[WHILE_COMMAND] = new LoopCommand();
    commands[IF_COMMAND] = new IfCommand();
}

CommandsCreator* CommandsCreator::getInstance()
{
    static CommandsCreator instance;
    return &instance;
}

ICommand* CommandsCreator::createCommand(string& commandName)
{
    ICommand* command = commands[commandName];
    if (command == NULL)
        command = commands[ASSIGNMENT_COMMAND];
    return command;
}

