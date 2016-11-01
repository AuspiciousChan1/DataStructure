#ifndef SingleLinkedList_HEADER
#define SingleLinkedList_HEADER
#include <iostream>
#include <cstdlib>

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

    void destroyList();
    void clearList();
    bool isElemExist(string elem);
    string getHead() throw(exception);//��ȡͷ��������
    string getElem(int n) throw(exception);//��ȡ��ͨ�ڵ������
    string getElemToScreen(int n, string elemName) throw(exception);//��ȡ��ͨ�ڵ������
    string addElemToEnd(string elem);//���Ԫ�ص�ĩβ
};
#endif // SingleLinkedList_HEADER
