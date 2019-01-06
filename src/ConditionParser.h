#ifndef PROJECT_CONDITION_H
#define PROJECT_CONDITION_H

#include <string>

using namespace std;

class ConditionParser {
public:
    ConditionParser() {}
    ConditionParser(string varName, string operation, string value);
    bool isConditionMet();
    void setParams(string varName, string operation, string value);

private:
    string varName, operation, value;
};


#endif //PROJECT_CONDITION_H
