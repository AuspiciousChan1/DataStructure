#include "SingleLinkedList.h"
#include "Stack.h"
#include "LinkedQueue.h"
#include "MyFunction.h"
#include "Constant.h"
#include "MyFunction.h"
#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    Constant *constant = new Constant();
    MyFunction myFunction;
    try
    {
        stringstream sstream;
        string str = "";
        Stack *myStack = new Stack(constant->getStackName());
        LinkedQueue *lQueue =  new LinkedQueue(constant->getLinkedQueueName());
        for(int i = 0; i < 50; i++)
        {
            sstream.clear();
            sstream << i;
            sstream >> str;
            myStack->push(str);
            lQueue->enQueue(str);
        }
        if(myStack->clearStack())
        {
            cout<<"true"<<endl;
        }
        else
        {
            cout<<"false"<<endl;
        }
        cout<<myStack->getTop()<<endl;
        cout<<myStack->pop()<<endl;
        cout<<myStack->pop()<<endl;
        cout<<myStack->getTop()<<endl;
    }
    catch(length_error &le)
    {
        myFunction.myPrintf("length_error:", le.what());
    }
    catch(out_of_range &ofr)
    {
        myFunction.myPrintf("out_of_range:", ofr.what());
    }
    catch(logic_error &le)
    {
        myFunction.myPrintf("logic_error:", le.what());
    }
    return 0;
}
