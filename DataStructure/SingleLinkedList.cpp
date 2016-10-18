#include "SingleLinkedList.h"
#include <string>
#include <stdexcept>

using namespace std;

SingleLinkedList::SingleLinkedList()
{
    data = "";
    next = NULL;
}
SingleLinkedList::SingleLinkedList(string data)
{
    SingleLinkedList *p = this;
    p -> data = data;
    next = NULL;
}

string SingleLinkedList::getElem(int n) throw(exception){
    if(n > 0)
    {
        SingleLinkedList *p = this;
        while(n --)
        {
            if(p -> next != NULL)
            {
                p = p -> next;
            }
            else
            {
                throw out_of_range("n大于元素个数");
            }
        }
        return p -> data;
    }
    else{
        throw out_of_range("n < 0");
    }
}

//添加元素到单链表尾部，元素不能为空，否则不执行操作
string SingleLinkedList::addElemToEnd(string elem){
    if(!elem.empty())
    {
        SingleLinkedList *p = this;
        SingleLinkedList *sll = new SingleLinkedList(elem);
        while(p -> next != NULL)
        {
            p = p -> next;
        }
        p -> next = sll;
    }
    return elem;
}



