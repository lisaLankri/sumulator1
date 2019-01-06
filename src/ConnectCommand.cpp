#include "ConnectCommand.h"
#include <iostream>
#include "Utils.h"
#include "DataWriterClient.h"

using namespace std;

void ConnectCommand::execute(vector <string>& arrCommands)
{
    vector<string> arrParams = Utils::splitToWords(*arrCommands.begin());
    arrCommands.erase(arrCommands.begin());
    if (arrParams.size() > 3){
        cout << "Connect command " << MESSAGE_SYNTAX_ERROR << endl;
    }
    else {
        vector<string>::iterator it = arrParams.begin();
        ++it; // skip the name of the command
        string hostName = *it;
        ++it; // skip the name of the command
        int portId = std::stoi(*it);
        cout << portId << endl;
        cout << hostName << endl;
        DataWriterClient::getInstance()->openClient(portId, hostName);
    }
}
