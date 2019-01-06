#include "Utils.h"
#include <iostream>
#include <sstream>


vector<string> Utils::splitToWords(const string& line)
{
    vector<string> words;
    // cover the case that we have a print command with a string that contains spaces inside
    if ((line.find("print") == 0) && (line.find_first_of('\"') != string::npos))
    {
        int pos = line.find_first_of('\"');
        words.push_back("print");
        words.push_back(line.substr(pos));
        return words;
    }
    istringstream iss(line);
    for(string s; iss >> s; )
        words.push_back(s);
    return words;
}

std::string Utils::ltrim(std::string str, const std::string& chars)
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

std::string Utils::rtrim(std::string str, const std::string& chars)
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

std::string Utils::trim(std::string str, const std::string& chars)
{
    return ltrim(rtrim(str, chars), chars);
}

void Utils::tokenize(const string& str, vector<string>& tokens, const string& delimiters)
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);

    // Find first non-delimiter.
    string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos) {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));

        // Skip delimiters.
        lastPos = str.find_first_not_of(delimiters, pos);

        // Find next non-delimiter.
        pos = str.find_first_of(delimiters, lastPos);
    }
}
