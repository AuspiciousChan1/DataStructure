#ifndef STACK_HEADER
#define STACK_HEADER

#include <iostream>
#include <cstdlib>


using namespace std;

class Stack{
private:
    string data;
    Stack *next;
public:
    Stack(string data);
    ~Stack();

    void destroyStack();
    void clearStack() throw(exception);
    bool isStackEmpty();
    int stackEmpty();
    string push(string data);
    string pop() throw(exception);

};

#endif // STACK_HEADER
