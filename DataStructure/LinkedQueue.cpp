#include "LinkedQueue.h"

using namespace std;

LinkedQueue::LinkedQueue(string data) throw(exception)
{
    if(data != "")
    {
        this->data = data;
        this->next = nullptr;
    }
    else
    {
        throw out_of_range("队列元素不能为空");
    }
}

LinkedQueue::~LinkedQueue()
{
    this->data = "";
    this->next = nullptr;
}

void LinkedQueue::destroyQueue()
{
    if(this->data != "")
    {
        if(this->next != nullptr)//如果链表不为空，删掉元素结点
        {
            LinkedQueue *p = this->next->next;//p指向队首
            this->next->next = nullptr;//转为头结点指向末尾的单链表
            LinkedQueue *q = p;
            while(p->next != nullptr)
            {
                q = p->next;
                delete p;
                p = q;
            }
            delete p;
        }
        else{}
        delete this;//删掉头结点
    }
    else{}
}

bool LinkedQueue::clearQueue()
{
    if(this->data != "")
    {
        if(this->next != nullptr)
        {
            LinkedQueue *p = this->next->next;
            LinkedQueue *q = nullptr;
            this->next->next = nullptr;
            while(p->next != nullptr)
            {
                q = p->next;
                delete p;
                p = q;
            }
            delete p;
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool LinkedQueue::isQueueEmpty() throw(exception)
{
    if(this->data != "")
    {
        return this->next == nullptr;
    }
    else
    {
        throw logic_error("队列不存在，无法定义是否为空");
    }
}

int LinkedQueue::getLength() throw(exception)
{
    if(this->data != "")
    {
        if(this->next != nullptr)
        {
            int n = 1;
            LinkedQueue *p = this->next;
            while(p->next != this->next)
            {
                n++;
                p = p->next;
            }
            return n;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        throw logic_error("队列不存在，获取队列长度失败！");
    }
}

string LinkedQueue::getQueueName() throw(exception)
{
    if(this->data != "")
    {
        return this->data;
    }
    else
    {
        throw logic_error("队列不存在，获取队列名称失败");
    }
}

string LinkedQueue::getStart() throw(exception)
{
    if(this->data != "")
    {
        if(this->next == nullptr)
        {
            return "";
        }
        else
        {
            return this->next->next->data;
        }
    }
    else
    {
        throw logic_error("队列不存在，获取队首失败！");
    }
}

string LinkedQueue::getEnd() throw(exception)
{
    if(this->data != "")
    {
        if(this->next == nullptr)
        {
            return "";
        }
        else
        {
            return this->next->data;
        }
    }
    else
    {
        throw logic_error("队列不存在，获取队尾失败！");
    }
}

bool LinkedQueue::enQueue(string str) throw(exception)
{
    if(this->data != "")
    {
        if(str == "")
        {
            return false;
        }
        else
        {
            LinkedQueue *lq = new LinkedQueue(str);
            if(this->next ==nullptr)
            {
                this->next = lq;
                lq->next = lq;//只有一个数据结点时，它的next指针指向自己
            }
            else
            {
                LinkedQueue *qend = this->next;
                LinkedQueue *qstart = qend->next;
                lq->next = qstart;
                qend->next = lq;
                this->next = lq;
            }
        }
    }
    else
    {
        throw logic_error("队列不存在，添加元素失败！");
    }
}

string LinkedQueue::deQueue() throw(exception)
{
    if(this->data != "")
    {
        if(this->next == nullptr)
        {
            return "";
        }
        else if(this->next == this->next->next)
        {
            string str = this->next->data;
            delete this->next;
            this->next = nullptr;
            return str;
        }
        else
        {
            LinkedQueue *qend = this->next;
            //cout<<"end："<<qend->data<<endl;
            LinkedQueue *qstart = qend->next;
            //cout<<"start："<<qstart->data<<endl;
            string str = qstart->data;
            qend->next = qstart->next;
            delete qstart;
            return str;
        }

    }
    else
    {
        throw logic_error("队列不存在，出队列失败！");
    }

}

//留底
