#include "Stack.h"
#include "Constant.h"
#include <string>
#include <stdexcept>


Stack::Stack(string data){
    this->data = data;
    this->next = nullptr;
}

Stack::~Stack(){
    data = "";
    next= nullptr;
}

//���ȥ��ͷ���
void Stack::destroyStack(){
    if(this != nullptr){
        Stack *p = this;
        Stack *q = p;
        while(p->next != nullptr){
            q = p->next;
            p->next = nullptr;
            delete p;
            p = q;
        }
        delete p;
    }
    else{
    }
    this->next = nullptr;
    delete this;
}

void Stack::clearStack()throw(exception){
    if(!(this->next == nullptr && this->data == "")){
        Stack *p = this->next;
        Stack *q = p;
        while(p->next != nullptr){
            q = p->next;
            delete p;
            p = q;
        }
        delete p;
        this->next = nullptr;
    }
    else{
        throw logic_error("ջ������");
    }
}

bool Stack::isStackEmpty(){
    return this->next == nullptr;
}

int Stack::stackEmpty(){
    Stack *p = this;
    int n = 0;
    while(p->next != nullptr){
        n++;
        p = p->next;
    }
    return n;
}

//��δ����thisΪ��ָ������
string Stack::push(string data){
    Stack *node = new Stack(data);
    if(this->next == nullptr){
        this->next = node;
    }
    else{
        Stack *p = this->next;
        node->next = p;
        this->next = node;
    }
    return data;
}

string Stack::pop() throw(exception){
    if(this->next == nullptr){
        throw out_of_range("ջΪ��");
    }
    else{
        Stack *p = this->next;
        this->next = p->next;
        string str = p->data;
        delete p;
        return str;
    }
}
