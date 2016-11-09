#ifndef LINKED_QUEUE_HEADER
#define LINKED_QUEUE_HEADER

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class LinkedQueue
{
private:
    string data;
    LinkedQueue *next;
public:
    LinkedQueue(string data) throw(exception);
    ~LinkedQueue();
    void destroyQueue();//如果队列不存在，则不操作。
    bool clearQueue();//队列存在则返回true，不存在返回false。
    bool isQueueEmpty() throw(exception);
    int getLength() throw(exception);
    string getQueueName() throw(exception);
    string getStart() throw(exception);
    string getEnd() throw(exception);
    bool enQueue(string str) throw(exception);
    string deQueue() throw(exception);
};

#endif // LINKED_QUEUE_HEADER
