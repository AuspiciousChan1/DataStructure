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
    bool clearStack();
    bool isStackEmpty() throw(exception);
    int getLength() throw(exception);
    string push(string data) throw(exception);
    string pop() throw(exception);
    string getName() throw(exception);
    string getTop() throw(exception);
};

#endif // STACK_HEADER
