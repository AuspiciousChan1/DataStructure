#include "SingleLinkedList.h"
#include "Stack.h"
#include <iostream>
#include <stdexcept>
#include <cstdio>

using namespace std;

int main()
{
    try{
        SingleLinkedList *sLList = new SingleLinkedList("test");
        Stack *myStack = new Stack("Test");
        char buffer[100];
        for(int i = 0; i <100; i++){
            sprintf(buffer, "%d", i);
            cout<<"push£º"<<myStack->push(buffer)<<endl;
        }
        cout<<"pop£º"<<myStack->pop()<<endl;
        myStack->destroyStack();
        myStack->clearStack();
    }
    catch(out_of_range &ofr){
        cout<<"Error:"<<ofr.what()<<endl;
    }
    catch(logic_error &le){
        cout<<"Error:"<<le.what()<<endl;
    }
    return 0;
}
