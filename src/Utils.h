#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H

#include <vector>
#include <string>
using namespace std;

class Utils {
public:
    static vector<string> splitToWords(const string& line);
    static std::string trim(std::string str, const std::string& chars = "\t\n\v\f\r ");
    static void tokenize(const string& str, vector<string>& tokens, const string& delimiters = ",");
private:
    static std::string ltrim(std::string str, const std::string& chars = "\t\n\v\f\r ");
    static std::string rtrim(std::string str, const std::string& chars = "\t\n\v\f\r ");

};


#endif //PROJECT_UTILS_H
