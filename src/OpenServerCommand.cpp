#include "OpenServerCommand.h"
#include "Utils.h"
#include "DataReaderServer.h"
#include <iostream>

using namespace std;

OpenServerCommand::OpenServerCommand(){

};

void OpenServerCommand::execute(vector<string>& arrCommands) {
    vector<string> arrParams = Utils::splitToWords(*arrCommands.begin());
    arrCommands.erase(arrCommands.begin());
    if (arrParams.size() > 3){
        cout << "OpenServer command " << MESSAGE_SYNTAX_ERROR << endl;
    }
    else{
         vector<string>::iterator it = arrParams.begin();
         ++it; // skip the name of the command
        int portId = std::stoi(*it);
        ++it; // skip the name of the command
        int timesPerSecond = std::stoi(*it);
        cout << portId << endl;
        cout << timesPerSecond << endl;
        DataReaderServer::getInstance()->openServer(portId, timesPerSecond);
    }
};

