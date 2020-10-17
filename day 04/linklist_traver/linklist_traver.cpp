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

Status InitList(LinkList &L)        // 初始化单链表
{
    L=(LinkList) malloc(sizeof(LNode));
    if(!L)  {   return Error;   }
    else L->next = NULL;
    return OK;
}

Status LinkListInsert(LinkList L,int i,datatype e)     // 插入元素e到指定单链表位置i
{
    LinkList p; 
    p = L;
    
    int j = 1;
    if(p && j < i)      // 链表还未空、还未到序号
    {
        p=L->next;      // 没有到指定位置则一直向后面的结点移动
        ++j;              
    }
    if(!p || j>i)       // 未找到此结点
    {
        return Error;
    }

    LNode *s;                                 
    s=(LinkList) malloc (sizeof(datatype));  // 给s分配内存
    s->data = e;          
    s->next = p->next;
    p->next = s;
    p->data = s->data;
    return OK;
}

Status visit(datatype e)     // 打印结点值e
{
    printf("%d  ",e);
    return OK;
}

Status LinkListTraver(LinkList L)  // 打印单链表的所有值
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
    
    srand(time(NULL));             // 随机数种子
    for(int i=0;i<n;i++)
    {
        datatype elem;
        elem = rand() % 100;
        LinkListInsert(L, 1, elem);     
    }
    LinkListTraver(L);          // 输出单链表
}
