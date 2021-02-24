#include <string>
#pragma once

enum class type { INT, BOOL, FLOAT, STRING };

class bucket{
private:
    int         myInt;
    bool        myBool;
    float       myFloat;
    std::string myString;
    type        myType;
public:
    bucket      operator*(const bucket& theirData);
    bucket      operator/(const bucket& theirData);
    bucket      operator+(const bucket& theirData);
    bucket      operator-(const bucket& theirData);
    void        operator=(const int& theirInt);
    void        operator=(const bool& theirBool);
    void        operator=(const float& theirFloat);
    void        operator=(const std::string& theirString);
    void        operator=(const bucket& theirData);
    bool        operator==(const bucket& theirData);
    bool        operator==(const type& theirType);
    type        getType();
    int         getInt();
    bool        getBool();
    std::string getString();
    float       getFloat();
};
