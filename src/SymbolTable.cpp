#include "SymbolTable.h"
#include "Utils.h"

SymbolTable::SymbolTable()
{
    bindNames.push_back("instrumentation/airspeed-indicator/indicated-speed-kt");
    bindNames.push_back("instrumentation/altimeter/indicated-altitude-ft");
    bindNames.push_back("instrumentation/altimeter/pressure-alt-ft");
    bindNames.push_back("instrumentation/attitude-indicator/indicated-pitch-deg");
    bindNames.push_back("instrumentation/attitude-indicator/indicated-roll-deg");
    bindNames.push_back("instrumentation/attitude-indicator/internal-pitch-deg");
    bindNames.push_back("instrumentation/attitude-indicator/internal-roll-deg");
    bindNames.push_back("instrumentation/encoder/indicated-altitude-ft");
    bindNames.push_back("instrumentation/encoder/pressure-alt-ft");
    bindNames.push_back("instrumentation/gps/indicated-altitude-ft");
    bindNames.push_back("instrumentation/gps/indicated-ground-speed-kt");
    bindNames.push_back("instrumentation/gps/indicated-vertical-speed");
    bindNames.push_back("instrumentation/heading-indicator/indicated-heading-deg");
    bindNames.push_back("instrumentation/magnetic-compass/indicated-heading-deg");
    bindNames.push_back("instrumentation/slip-skid-ball/indicated-slip-skid");
    bindNames.push_back("instrumentation/turn-indicator/indicated-turn-rate");
    bindNames.push_back("instrumentation/vertical-speed-indicator/indicated-speed-fpm");
    bindNames.push_back("controls/flight/aileron");
    bindNames.push_back("controls/flight/elevator");
    bindNames.push_back("controls/flight/rudder");
    bindNames.push_back("controls/flight/flaps");
    bindNames.push_back("controls/engines/engine/throttle");
    bindNames.push_back("engines/engine/rpm");
}

SymbolTable* SymbolTable::getInstance()
{
    static SymbolTable instance;
    return &instance;
}

SymbolTable::~SymbolTable()
{
    // delete allocated memory
    for (map<string, VariableInfo*>::iterator it = commands.begin(); it != commands.end(); it++ )
    {
        delete it->second;
    }
}

void SymbolTable::addVariableInfo(string name, double value)
{
    VariableInfo* var = new VariableInfo;
    var->name = name;
    var->value = value;
    commands[name] = var;
}

void SymbolTable::addVariableInfo(string name, string bindName)
{
    VariableInfo* var = new VariableInfo;
    var->name = name;
    var->bindName = bindName;
    commands[name] = var;
    bindToValues[bindName] = var;
}

void SymbolTable::updateValues(string values)
{
    vector<string> tokens;
    Utils::tokenize(values, tokens);
    double value;
    string bind;
    VariableInfo* varInfo;
    for (unsigned i = 0; i < tokens.size(); i++)
    {
        value = std::stod(tokens[i]);
        if (i < bindNames.size()) {
            bind = bindNames[i];
            varInfo = bindToValues[bind];
            if (varInfo != NULL)
                varInfo->value = value;
        }
    }
}

VariableInfo* SymbolTable::SymbolTable::getInfo(string name)
{
    return commands[name];
}

