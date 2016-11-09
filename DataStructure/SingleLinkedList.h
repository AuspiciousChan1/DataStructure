#ifndef SingleLinkedList_HEADER
#define SingleLinkedList_HEADER
#include <string>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

class SingleLinkedList
{
private:
    string data;
    SingleLinkedList *next;
public:
    SingleLinkedList(string data);
    ~SingleLinkedList(){}

    void destroyList();
    void clearList();
    bool isElemExist(string elem);
    string getHead() throw(exception);//获取头结点的内容
    string getElem(int n) throw(exception);//获取普通节点的内容
    string getElemToScreen(int n, string elemName) throw(exception);//获取普通节点的内容
    string addElemToEnd(string elem);//添加元素到末尾
};
#endif // SingleLinkedList_HEADER
