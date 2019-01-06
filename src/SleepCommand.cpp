#include "SleepCommand.h"
#include <unistd.h>
#include <iostream>
#include "Utils.h"
#include <chrono>
#include <thread>

using namespace std;

void SleepCommand::execute(vector <string>& arrCommands)
{
    vector<string> arrParams = Utils::splitToWords(*arrCommands.begin());
    arrCommands.erase(arrCommands.begin());
    if (arrParams.size() != 2){
        cout << "SleepCommand " << MESSAGE_SYNTAX_ERROR << endl;
    }
    else {
        vector<string>::iterator it = arrParams.begin();
        ++it; // skip the command name
        string value = *it;
        std::this_thread::sleep_for(std::chrono::milliseconds(std::stoi(value)));
    }
}
