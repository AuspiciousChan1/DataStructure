#ifndef _SingleLinkedList_HEADER
#define _SingleLinkedList_HEADER
#include "SingleLinkedList.h"
#endif

#include <iostream>
#include <stdexcept>
#include <cstdio>

using namespace std;

int main()
{
    SingleLinkedList *sLList = new SingleLinkedList("test");

    sLList -> addElemToEnd("1");
    sLList -> addElemToEnd("2");
    sLList -> addElemToEnd("3");
    sLList -> addElemToEnd("4");
    sLList -> addElemToEnd("5");
    cout << sLList -> getElem(4)<<endl;
    try{
        cout << sLList -> getElem(-1)<<endl;
    }
    catch(out_of_range &e){
        cout<<"Error:"<<e.what()<<endl;
    }
    try{
        cout << sLList -> getElem(6)<<endl;
    }
    catch(out_of_range &e){
        cout<<"Error:"<<e.what()<<endl;
    }
    return 0;
}
