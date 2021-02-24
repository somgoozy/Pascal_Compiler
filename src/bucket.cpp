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
                    //throw error
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
                    //throw error; invalid type
                    break;
                }
            }
            break;
        }
        default: {
            //throw error; invalid type
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
                        //throw error; invalid type
                        break;
                    }
                }
            }
            else {
                //throw error; cannot divide by zero
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
                        //throw error; invalid type
                        break;
                    }
                }
            }
            else {
                //throw error; cannot divide by zero
            }
            break;
        }
        default:{
            //throw error; invalid type
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
                    //throw error; invalid type
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
                    //throw error
                    break;
                }
            }
            break;
        }
        default: {
            //throw error; invalid type
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
                    retData.myFloat = myInt - theirBucket.myFloat;
                    retData.myType = type::FLOAT;
                    return retData;
                    break;
                }
                case type::FLOAT: {
                    retData.myFloat = myFloat - theirBucket.myFloat;
                    retData.myType = type::FLOAT;
                    return retData;
                    break;
                }
                default: {
                    //throw error
                    break;
                }
            }
            break;
        }
        case type::INT: {
            switch(myType) {
                case type::INT: {
                    retData.myInt = myInt - theirBucket.myInt;
                    retData.myType = type::INT;
                    return retData;
                    break;
                }
                case type::FLOAT: {
                    retData.myFloat = myFloat - theirBucket.myInt;
                    retData.myType = type::FLOAT;
                    return retData;
                    break;
                }
                default: {
                    //throw error
                    break;
                }
            }
            break;
        }
        default: {
            //throw error; invalid type
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
            myType = theirBucket.myType;
            break;
        }
        case(type::INT): {
            myInt = theirBucket.myInt;
            myType = theirBucket.myType;
            break;
        }
        case(type::FLOAT): {
            myFloat = theirBucket.myFloat;
            myType = theirBucket.myType;
            break;
        }
        case(type::STRING): {
            myString = theirBucket.myString;
            myType = theirBucket.myType;
            break;
        }
        default: {
            //throw error; unknown type
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
