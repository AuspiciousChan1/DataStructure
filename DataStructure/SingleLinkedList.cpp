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
    this->next = nullptr;//若不标注next会指向已经被释放打你地址
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
        throw length_error("this为空指针");
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
                throw length_error("n大于元素个数");
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
                throw length_error("n大于元素个数");
            }
        }
        cout << elemName << "：" << p->data <<endl;
        return p -> data;
    }
    else{
        throw length_error("n < 1");
    }
}

//添加元素到单链表尾部，元素不能为空，否则不执行操作
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



