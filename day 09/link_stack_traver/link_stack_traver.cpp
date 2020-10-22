// 用队列实现任意输入一串字符串，以#作为结束标志,程序将字符串输出在屏幕上
// 2020-10-22
// fyj

#include <iostream>

#define OK 1
#define ERROR -1
#define True 1
#define False 0
#define Status int
#define ElemType char

typedef  struct QNode
{
    ElemType data;
    QNode *next;
}QNode,*QueuePtr;  // 队结点

typedef struct 
{
    QNode * front, *rear;
}LinkQueue;  // 链队

Status LinkQueue_init(LinkQueue &q)
{
    QueuePtr s;
    s = (QueuePtr) malloc (sizeof(QNode));
    if(!s) return ERROR;
    // s->data = NULL;
    q.front = q.rear = s;
    return OK;
}

Status Add(LinkQueue &q,ElemType e)
{
    QueuePtr s;
    s = (QueuePtr) malloc (sizeof(QNode)); 
    if(!s) return ERROR;
    s->data = e;
    q.rear->next = s;
    q.rear = s;
    q.rear->next = NULL;
    return OK;
}

Status LinkQueue_traver(LinkQueue &q)
{
    while(q.front != q.rear)
    {
        QueuePtr s;
        s= (QueuePtr) malloc (sizeof(QNode));
        if(!s) return ERROR;
        
        if(q.front->next == q.rear)
        {
            s = q.front->next;
            printf("%c",s->data);
            q.front = q.rear;
            free(s);
            return False;
        }
        else
        {
            s = q.front->next;
            printf("%c",s->data);
            q.front->next = q.front->next->next;
            free(s);
        }
    }
    return OK;
}

int main()
{
    LinkQueue q;
    LinkQueue_init(q);
    printf("请输入字符串，以#作为字符串结束标志.\n");
    printf("->");
    ElemType e;
    scanf("%c",&e);
    while(True)
    {
        Add(q,e);
        scanf("%c",&e);
        if(e=='#') 
        {
            LinkQueue_traver(q);
            return False;
        }
    }
}