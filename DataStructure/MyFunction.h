#ifndef MY_FUNCTION_HEADER
#define MY_FUNCTION_HEADER

#include <iostream>
#include <cstdio>
#include <string>
#include <sStream>
#include <typeinfo>

using namespace std;

class MyFunction
{
public:
    string static intToString(int t);
    void myPrintf(string inf);
    void myPrintf(string title, string inf);
};

#endif // MY_FUNCTION_HEADER
