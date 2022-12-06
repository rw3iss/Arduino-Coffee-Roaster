#pragma once

#include <sstream>
#include <string>

using namespace std;

template <typename T>
string NumberToString(T pNumber) {
    ostringstream oOStrStream;
    oOStrStream << pNumber;
    return oOStrStream.str();
}