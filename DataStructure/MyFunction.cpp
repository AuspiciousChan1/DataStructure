#include "MyFunction.h"

using namespace std;

string MyFunction::intToString(int t)
{
    stringstream sStream;
    sStream.clear();
    sStream << t;
    string str = "";
    sStream >> str;
    return str;
}

void MyFunction::myPrintf(string inf)
{
    puts("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    putchar('\t');
    cout<<inf;
    puts("\n==============================================================");
}

void MyFunction::myPrintf(string title, string inf)
{
    puts("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
    cout<<title;
    putchar('\n');
    putchar('\t');
    cout<<inf;
    puts("\n==============================================================");
}


//Áôµ×
