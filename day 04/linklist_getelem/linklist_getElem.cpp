/*
 * 实现头插法创建单链表，并打印生成的单链表数据
 * 2020/10/14
 * fyj
 */

#include <cstdlib>
#include <iostream>
#include "time.h"
#include "stdlib.h"

using namespace std;

#define OK 1
#define Error 0
#define True 1
#define False 0
#define maxsize 50

typedef int Status;
typedef int datatype;

typedef struct LNode       // 定义链表的结点结构
{
    datatype data;        // 保存结点数据域
    struct LNode *next;   // 结点的指针域，保存下一结点的地址
} LNode,*LinkList;

typedef struct LNode * LinkList; // 创建一个表LinkList

Status InitList(LinkList &L)
{
    L=(LinkList) malloc(sizeof(LNode));
    if(!L)  {   return Error;   }
    else L->next = NULL;
    return OK;
}

Status LinkListInsert(LinkList L,int i,datatype e)
{
    LinkList p; // 单链表的下一个结点
    p = L;
    
    int j = 1;
    if(p && j < i)
    {
        p=L->next;
        ++j;
    }
    if(!p || j>i)      // 未找到此结点
    {
        return Error;
    }
    LinkList s;                                 
    s=(LinkList) malloc (sizeof(datatype));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status visit(datatype e)
{
    printf("%d  ",e);
    return OK;
}

Status LinkListTraver(LinkList L)
{
    LinkList s;
    s = L->next;
    while (s)
    {
        visit(s->data);
        s=s->next;
    }
    printf("\n");
    return OK;
}

int main()
{
    LinkList L;
    InitList(L);
    printf("请输入单链表的长度: ");
    int n;
    cin>>n;
    
    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        datatype elem;
        elem = rand() % 100;
        LinkListInsert(L, 1, elem);
    }
    LinkListTraver(L);
}
