#include "bucket.h"

bucket bucket::operator*(const bucket& theirBucket) {
    bucket retData;
    switch(theirBucket.myType) {
        case type::FLOAT: {
            switch(myType) {
                case type::INT: {
                    //int * float
                    retData.myFloat = myInt * theirBucket.myFloat;
                    retData.myType = type::FLOAT;
                    return retData;
                    break;
                }
                case type::FLOAT: {
                    //float * float
                    retData.myFloat = myFloat * theirBucket.myFloat;
                    retData.myType = type::FLOAT;
                    return retData;
                    break;
                }
                default: {
                    throw std::invalid_argument("Cannot multiply types" + stringType(myType) + " and FLOAT\n");
                    break;
                }
            }
            break;
        }
        case type::INT: {
            switch(myType) {
                case type::INT: {
                    //int * int
                    retData.myInt = myInt * theirBucket.myInt;
                    retData.myType = type::INT;
                    return retData;
                    break;
                }
                case type::FLOAT: {
                    //float * int
                    retData.myFloat = myFloat * theirBucket.myInt;
                    retData.myType = type::FLOAT;
                    return retData;
                    break;
                }
                default: {
                    throw std::invalid_argument("Cannot multiply types" + stringType(myType) + " and INT\n");
                    break;
                }
            }
            break;
        }
        default: {
            throw std::invalid_argument("Cannot multiply types" + stringType(myType) + " and " + stringType(theirBucket.myType) + "\n");
            break;
        }
    }
    return retData;
}

bucket bucket::operator/(const bucket& theirBucket) {
    bucket retData;
    switch(theirBucket.myType) {
        case type::FLOAT: {
            if(theirBucket.myFloat != 0) {
                switch(myType) {
                    case type::INT: {
                        //int / float
                        retData.myInt = (int)(myInt / theirBucket.myFloat);
                        retData.myType = type::INT;
                        return retData;
                        break;
                    }
                    case type::FLOAT: {
                        //float / float
                        retData.myInt = (int)(myFloat / theirBucket.myFloat);
                        retData.myType = type::INT;
                        return retData;
                        break;
                    }
                    default: {
                        throw std::invalid_argument("Cannot divide types" + stringType(myType) + " and FLOAT\n");
                        break;
                    }
                }
            }
            else {
                throw std::invalid_argument("Cannot divide by 0\n");
            }
            break;
        }
        case type::INT: {
            if(theirBucket.myInt != 0) {
                switch(myType) {
                    case type::INT: {
                        //int / int
                        retData.myInt = myInt / theirBucket.myInt;
                        retData.myType = type::INT;
                        return retData;
                        break;
                    }
                    case type::FLOAT: {
                        //float / int
                        retData.myFloat = (int)(myFloat / theirBucket.myInt);
                        retData.myType = type::INT;
                        return retData;
                        break;
                    }
                    default: {
                        throw std::invalid_argument("Cannot divide types" + stringType(myType) + " and INT\n");
                        break;
                    }
                }
            }
            else {
                throw std::invalid_argument("Cannot divide by 0\n");
            }
            break;
        }
        default:{
            throw std::invalid_argument("Cannot divide types" + stringType(myType) + " and " + stringType(theirBucket.myType) + "\n");
            break;
        }
    }
    return retData;
}

bucket bucket::operator+(const bucket& theirBucket) {
    bucket retData;
    switch(theirBucket.myType) {
        case type::FLOAT: {
            switch(myType) {
                case type::INT: {
                    //int + float
                    retData.myFloat = myInt + theirBucket.myFloat;
                    retData.myType = type::FLOAT;
                    return retData;
                    break;
                }
                case type::FLOAT: {
                    //float + float
                    retData.myFloat = myFloat + theirBucket.myFloat;
                    retData.myType = type::FLOAT;
                    return retData;
                    break;
                }
                default: {
                    throw std::invalid_argument("Cannot add types" + stringType(myType) + " and FLOAT\n");
                    break;
                }
            }
            break;
        }
        case type::INT: {
            switch(myType) {
                case type::INT: {
                    //int + int
                    retData.myInt = myInt + theirBucket.myInt;
                    retData.myType = type::INT;
                    return retData;
                    break;
                }
                case type::FLOAT: {
                    //float + int
                    retData.myFloat = myFloat + theirBucket.myInt;
                    retData.myType = type::FLOAT;
                    return retData;
                    break;
                }
                default: {
                    throw std::invalid_argument("Cannot add types" + stringType(myType) + " and INT\n");
                    break;
                }
            }
            break;
        }
        default: {
            throw std::invalid_argument("Cannot add types" + stringType(myType) + " and " + stringType(theirBucket.myType) + "\n");
            break;
        }
    }
    return retData;
}

bucket bucket::operator-(const bucket& theirBucket) {
    bucket retData;
    switch(theirBucket.myType) {
        case type::FLOAT: {
            switch(myType) {
                case type::INT: {
                    //int - float
                    retData.myFloat = myInt - theirBucket.myFloat;
                    retData.myType = type::FLOAT;
                    return retData;
                    break;
                }
                case type::FLOAT: {
                    //float - float
                    retData.myFloat = myFloat - theirBucket.myFloat;
                    retData.myType = type::FLOAT;
                    return retData;
                    break;
                }
                default: {
                    throw std::invalid_argument("Cannot subtract types" + stringType(myType) + " and FLOAT\n");
                    break;
                }
            }
            break;
        }
        case type::INT: {
            switch(myType) {
                case type::INT: {
                    //int - int
                    retData.myInt = myInt - theirBucket.myInt;
                    retData.myType = type::INT;
                    return retData;
                    break;
                }
                case type::FLOAT: {
                    //float - int
                    retData.myFloat = myFloat - theirBucket.myInt;
                    retData.myType = type::FLOAT;
                    return retData;
                    break;
                }
                default: {
                throw std::invalid_argument("Cannot subtract types" + stringType(myType) + " and INT\n");
                    break;
                }
            }
            break;
        }
        default: {
            throw std::invalid_argument("Cannot subtract types" + stringType(myType) + " and " + stringType(theirBucket.myType) + "\n");
            break;
        }
    }
    return retData;
}

void bucket::operator=(const int& theirInt) {
    myInt = theirInt;
    myType = type::INT;
}

void bucket::operator=(const bool& theirBool) {
    myBool = theirBool;
    myType = type::BOOL;
}

void bucket::operator=(const float& theirFloat) {
    myFloat = theirFloat;
    myType = type::FLOAT;
}

void bucket::operator=(const std::string& theirString) {
    myString = theirString;
    myType = type::STRING;
}

void bucket::operator=(const bucket& theirBucket) {
    myType = theirBucket.myType;
    switch (theirBucket.myType) {
        case(type::BOOL): {
            myBool = theirBucket.myBool;
            break;
        }
        case(type::INT): {
            myInt = theirBucket.myInt;
            break;
        }
        case(type::FLOAT): {
            myFloat = theirBucket.myFloat;
            break;
        }
        case(type::STRING): {
            myString = theirBucket.myString;
            break;
        }
        case(type::UNINITIALIZED): {
            break;
        }
        default: {
            throw std::invalid_argument("Unrecognized type!");
        }
    }
}

bool bucket::operator==(const bucket& theirBucket) {
    if (myType == theirBucket.myType){
        return true;
    }
    return false;
}

bool bucket::operator==(const type& theirType) {
    if (myType == theirType){
        return true;
    }
    return false;
}

type bucket::getType() {
    return myType;
}

int bucket::getInt() {
    return myInt;
}

bool bucket::getBool() {
    return myBool;
}

float bucket::getFloat() {
    return myFloat;
}

std::string bucket::getString() {
    return myString;
}

std::string bucket::stringType(type t) {
    switch(t) {
        case type::STRING: {
            return "STRING";
            break;
        }
        case type::INT: {
            return "INT";
            break;
        }
        case type::FLOAT: {
            return "REAL";
            break;
        }
        case type::BOOL: {
            return "BOOLEAN";
            break;
        }
        case type::UNINITIALIZED: {
            return "UNINITIALIZED";
            break;
        }
        default: {
            throw std::invalid_argument("Unrecognized type!");
        }
    }
}

bucket::bucket() {
    myType = type::UNINITIALIZED;
}
