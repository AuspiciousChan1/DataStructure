#ifndef CONSTANT_HEADER
#define CONSTANT_HEADER
#include <iostream>
#include <string>

using namespace std;

class Constant
{
private:
    string stackName;
    string linkedQueueName;
public:
    Constant();
    ~Constant();
    string getStackName();
    string getLinkedQueueName();
};

#endif
