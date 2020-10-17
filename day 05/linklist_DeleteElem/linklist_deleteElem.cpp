// 创建一个单链表(元素为整数)，删除用户指定位置的结点
// 2020-10-17
// fyj


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

#define datatype int
#define Status int
#define OK 1
#define Error -1
#define True  1
#define False 0

typedef struct LNode
{
    datatype data;
    LNode * next;
}LNode, *LinkList;

Status InitLinkList(LinkList &L)
{
    L=(LinkList) malloc (sizeof(LNode));
    if(!L) {return Error;}
    else
    {
        L->next = NULL;
    }
    return OK;
}

Status LinkListInsert(LinkList L,int i,datatype elem)
{
    int j;
    LinkList p;
    p=L;
    if(p && j < i)
    {
        p=L->next;
        ++j;
    }
    if(!p || j>i)
    {
        return Error;  // 没找到此位置
    }
    
    LNode *s;
    s=(LinkList) malloc (sizeof(LNode));
    s->data = elem;
    s->next = L->next;
    L->next = s;
    L->data = s->data;
    return OK;
}

Status LinkListDeleteElem(LinkList L,int i)
{
    for(int j=1;j<i+1;j++)
    {
        L=L->next;
        if(j==i-1)
        {
            L->next = L->next->next;
            break;
        }
    }
    return OK;
}

Status LinkList_Traver(LinkList L)
{
    L = L->next;

    while(L)
    {
        printf("%d  ",L->data);
        L = L->next;
    }
    return OK;
}

int main()
{
    LinkList L;
    InitLinkList(L);
    printf("请输入你要创建的链表元素个数: ");
    int num;
    scanf("%d",&num);
    datatype elem;

    for(int i = 0;i<num;i++)
    {
        printf("请输入元素: ");
        scanf("%d",&elem);
        LinkListInsert(L, i, elem);
    }
    LinkList_Traver(L);
    
    printf("\n请输入你要删除的元素序号: ");
    int elem_num;
    scanf("%d",&elem_num);
    LinkListDeleteElem(L,elem_num);
    LinkList_Traver(L);
}