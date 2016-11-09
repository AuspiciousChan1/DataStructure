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
        throw out_of_range("����Ԫ�ز���Ϊ��");
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
        if(this->next != nullptr)//�������Ϊ�գ�ɾ��Ԫ�ؽ��
        {
            LinkedQueue *p = this->next->next;//pָ�����
            this->next->next = nullptr;//תΪͷ���ָ��ĩβ�ĵ�����
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
        delete this;//ɾ��ͷ���
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
        throw logic_error("���в����ڣ��޷������Ƿ�Ϊ��");
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
        throw logic_error("���в����ڣ���ȡ���г���ʧ�ܣ�");
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
        throw logic_error("���в����ڣ���ȡ��������ʧ��");
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
        throw logic_error("���в����ڣ���ȡ����ʧ�ܣ�");
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
        throw logic_error("���в����ڣ���ȡ��βʧ�ܣ�");
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
                lq->next = lq;//ֻ��һ�����ݽ��ʱ������nextָ��ָ���Լ�
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
        throw logic_error("���в����ڣ����Ԫ��ʧ�ܣ�");
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
            //cout<<"end��"<<qend->data<<endl;
            LinkedQueue *qstart = qend->next;
            //cout<<"start��"<<qstart->data<<endl;
            string str = qstart->data;
            qend->next = qstart->next;
            delete qstart;
            return str;
        }

    }
    else
    {
        throw logic_error("���в����ڣ�������ʧ�ܣ�");
    }

}

//����
