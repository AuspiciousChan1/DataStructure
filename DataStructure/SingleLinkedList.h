#ifndef SingleLinkedList_HEADER
#define SingleLinkedList_HEADER
#include <iostream>

using namespace std;

class SingleLinkedList
{
private:
    string data;
    SingleLinkedList *next;
public:
    SingleLinkedList();
    SingleLinkedList(string data);
    ~SingleLinkedList(){}

    string getElem(int n) throw(exception);
    string addElemToEnd(string elem);
};
#endif // SingleLinkedList_HEADER
