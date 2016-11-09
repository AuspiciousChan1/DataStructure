#include "Stack.h"
#include <string>
#include <stdexcept>


Stack::Stack(string data){
    if(data != "")
    {
        this->data = data;
        this->next = nullptr;
    }
    else
    {
        throw out_of_range("栈名不能为空！");
    }
}

Stack::~Stack(){
    //cout<<"ClearStack："<<data<<endl;
    data = "";
    next= nullptr;
}

//如何去掉头结点
void Stack::destroyStack(){
    if(this != nullptr){
        Stack *p = this;
        Stack *q = nullptr;
        q = p;
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
}

bool Stack::clearStack(){
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
        return true;
    }
    else{
        return false;
    }
}

bool Stack::isStackEmpty() throw(exception){
    if(this->data != "")
    {
        return this->next == nullptr;
    }
    else
    {
        throw logic_error("栈不存在，无法定义空！");
    }
}

int Stack::getLength() throw(exception){
    if(this->data != "")
    {
        Stack *p = this;
        int n = 0;
        while(p->next != nullptr){
            n++;
            p = p->next;
        }
        return n;
    }
    else
    {
        throw logic_error("栈不存在");
    }
}

string Stack::push(string data) throw(exception){

    if(this->data != "")
    {
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
    else
    {
        throw logic_error("栈不存在，无法推元素入栈！");
    }
}

string Stack::pop() throw(exception){
    if(this->data == "")
    {
        throw logic_error("栈不存在，出栈失败！");
    }
    else if(this->next == nullptr){
        throw length_error("栈为空，无可出栈元素！");
    }
    else{
        Stack *p = this->next;
        this->next = p->next;
        string str = p->data;
        delete p;
        return str;
    }
}

string Stack::getName() throw(exception)
{
    if(this->data != "")
    {
        return this->data;
    }
    else
    {
        throw logic_error("栈不存在");
    }
}

string Stack::getTop() throw(exception)
{
    if(this->data != "")
    {
        if(this->next != nullptr)
        {
            return this->next->data;
        }
        else
        {
            throw length_error("栈为空，栈顶无元素！");
        }
    }
    else
    {
        throw logic_error("栈不存在");
    }
}

//留底

