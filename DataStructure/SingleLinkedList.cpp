#include "SingleLinkedList.h"
#include <string>

using namespace std;

SingleLinkedList::SingleLinkedList()
{
    data = "";
    next = NULL;
}
SingleLinkedList::SingleLinkedList(string data)
{
    SingleLinkedList *p = this;
    this->data = data;
    next = NULL;
}

string SingleLinkedList::addElemToEnd(string elem)
{

}
