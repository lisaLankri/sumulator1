#include "Parser.h"
#include "CommandsCreator.h"
#include "ICommand.h"
#include <string>
#include <iostream>

#include <sstream>

Parser::Parser()
{
}

void Parser::start(vector<string>& commands){
    while (commands.size() != 0) {
        run(commands);
    }
}

void Parser::run(vector<string>& commands)
{
    string tmpCommand;
    auto it = commands.begin();
    tmpCommand = *it;
    string firstWord = tmpCommand.substr(0, tmpCommand.find(" "));
    ICommand* command = CommandsCreator::getInstance()->createCommand(firstWord);
    if (command == NULL) {
        cout << "Command " << firstWord << " not found" << endl;
        commands.erase(commands.begin());
        return;
    }
    command->execute(commands);
}
