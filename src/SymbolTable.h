#ifndef PROJECT_SYMBOLTABLE_H
#define PROJECT_SYMBOLTABLE_H

#include <string>
#include <map>
#include <vector>

using namespace std;

struct VariableInfo
{
    VariableInfo() : value(0.0) {}
    string name;
    string bindName;
    double value;
};

class SymbolTable {
public:
    ~SymbolTable();
    static SymbolTable* getInstance();
    void addVariableInfo(string name, string bindName);
    void addVariableInfo(string name, double value);
    VariableInfo* getInfo(string name);
    void updateValues(string values);

private:
    SymbolTable();
    map<string, VariableInfo*> commands;
    map<string, VariableInfo*> bindToValues;
    vector<string> bindNames;
};

#endif //PROJECT_SYMBOLTABLE_H
