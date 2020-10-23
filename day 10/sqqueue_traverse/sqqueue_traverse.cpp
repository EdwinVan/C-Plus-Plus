// 使用队列的顺序存储结构存入用户输入的字符串（以#作为字符串结束标志），程序输出打印字符串
// 2020-10-23
// fyj

#include <iostream>

#define OK 1
#define ERROR -1
#define True 1
#define False 0
#define QElemType char
#define Status int
#define MAXSIZE 150

typedef struct
{
    QElemType * base;
    int front;
    int rear;
}SqQueue;

Status init_Queue(SqQueue &Q)
{
    Q.base = (QElemType*) malloc (MAXSIZE*sizeof(QElemType));
    if(!Q.base) return ERROR;
    Q.front = Q.rear = 0;
    return OK;
}
Status EnQueue(SqQueue &Q,QElemType e)
{
    if((Q.rear+1)%MAXSIZE==Q.front)
    {
        return ERROR;
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1) % MAXSIZE;
    return OK;
}

Status DeQueue(SqQueue &Q,QElemType &elem)
{
    if(Q.front == Q.rear)
    {
        return ERROR;
    }
    else
    {
        elem = Q.base[Q.front];
        Q.front = (Q.front+1)%MAXSIZE;
    }
    return OK;
}

Status Sqqueue_traverse(SqQueue &Q)
{
    while(Q.front != Q.rear)
    {
        QElemType elem;
        DeQueue(Q,elem);
        printf("%c",elem);
    }
    return OK;
}

int main()
{
    SqQueue Q;
    init_Queue(Q);
    printf("请输入字符串（以#作为字符串结束标志）: \n");
    QElemType e;
    scanf("%c",&e);
    while(e!='#')
    {
        EnQueue(Q,e);
        scanf("%c",&e);
    }

    Sqqueue_traverse(Q);
}
