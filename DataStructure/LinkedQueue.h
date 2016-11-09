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
    void destroyQueue();//������в����ڣ��򲻲�����
    bool clearQueue();//���д����򷵻�true�������ڷ���false��
    bool isQueueEmpty() throw(exception);
    int getLength() throw(exception);
    string getQueueName() throw(exception);
    string getStart() throw(exception);
    string getEnd() throw(exception);
    bool enQueue(string str) throw(exception);
    string deQueue() throw(exception);
};

#endif // LINKED_QUEUE_HEADER
