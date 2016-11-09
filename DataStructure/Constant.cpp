#include "Constant.h"

Constant::Constant()
{
    this->stackName = "Test";
    this->linkedQueueName = "Test";
}

Constant::~Constant()
{
    this->stackName = "";
}

string Constant::getStackName()
{
    return this->stackName;
}
string Constant::getLinkedQueueName()
{
    return this->linkedQueueName;
}
