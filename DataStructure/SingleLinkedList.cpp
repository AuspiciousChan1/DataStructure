#include "SingleLinkedList.h"

using namespace std;

SingleLinkedList::SingleLinkedList(string data)
{
    SingleLinkedList *p = this;
    next = nullptr;
    p -> data = data;
}

void SingleLinkedList::destroyList(){
        SingleLinkedList *p = this;
        SingleLinkedList *pNext = this;
        if(p->next != nullptr){
            pNext = p->next;
            while(pNext->next != nullptr){
                p = pNext;
                pNext = pNext->next;
                delete p;
            }
            delete pNext;
        }
        else{
            delete pNext;
        }

        delete this;
    }

void SingleLinkedList::clearList(){
    SingleLinkedList *p = this;
    SingleLinkedList *pNext = this;
    if(p->next != nullptr){
        pNext = p->next;
        while(pNext->next != nullptr){
            p = pNext;
            pNext = pNext->next;
            delete p;
        }
        delete pNext;
    }
    else{
        delete pNext;
    }
    this->data = "";
    this->next = nullptr;//������עnext��ָ���Ѿ����ͷŴ����ַ
}

bool SingleLinkedList::isElemExist(string elem){
    SingleLinkedList *p = this;
    while(p->next != nullptr)
    {
        p = p->next;
        if(p->data == elem)
        {
            return true;
        }
    }
    return false;
}

string SingleLinkedList::getHead() throw(exception){
    if(this != nullptr){
        return this -> data;
    }
    else{
        throw length_error("thisΪ��ָ��");
    }
}

string SingleLinkedList::getElem(int n) throw(exception){
    if(n > 0)
    {
        SingleLinkedList *p = this;
        while(n --)
        {
            if(p -> next != nullptr)
            {
                p = p -> next;
            }
            else
            {
                throw length_error("n����Ԫ�ظ���");
            }
        }
        return p -> data;
    }
    else{
        throw length_error("n < 1");
    }
}

string SingleLinkedList::getElemToScreen(int n, string elemName) throw(exception){
    if(n > 0)
    {
        SingleLinkedList *p = this;
        while(n --)
        {
            if(p -> next != nullptr)
            {
                p = p -> next;
            }
            else
            {
                throw length_error("n����Ԫ�ظ���");
            }
        }
        cout << elemName << "��" << p->data <<endl;
        return p -> data;
    }
    else{
        throw length_error("n < 1");
    }
}

//���Ԫ�ص�������β����Ԫ�ز���Ϊ�գ�����ִ�в���
string SingleLinkedList::addElemToEnd(string elem){
    SingleLinkedList *p = this;
    SingleLinkedList *sll = new SingleLinkedList(elem);
    while(p -> next != NULL)
    {
        p = p -> next;
    }
    p -> next = sll;
    return "";
}



