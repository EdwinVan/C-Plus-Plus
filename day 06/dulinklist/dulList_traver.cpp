// 创建双向链表存入26个英文大写字母，执行打印所有字母操作
// 2020/10/18
// fyj

#include <corecrt_math.h>
#include <iostream>
#include <string>
#include "stdlib.h"

#define  Status int
#define OK 1
#define True 1
#define False 0
#define ERROR -1
#define ElemType char


typedef struct DuLNode
{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
} DuLNode,*DuLinkList;

Status DuLList_Init(DuLinkList *L)
{
    *L = (DuLinkList) malloc (sizeof(DuLNode));
    if(!L) {return OVERFLOW;}
    (*L)->prior = (*L)->next = *L;
    return OK;
}

Status DuLList_Traver(DuLinkList *L)
{
    (*L)=(*L)->next;
    for(int j =0;j<26;j++)
    {
        printf("%c",(*L)->data);
        (*L)=(*L)->next;
    }
    printf("\n");
    return OK;
}

Status DuLList_Creat(DuLinkList *L)
{
    int i;
    DuLNode *p,*q;
    p = *L;
    for(i=0;i<=26;i++)
    {
        q = (DuLinkList) malloc(sizeof(DuLNode));
        if(!q) return ERROR;
        q->data = 'A' + i;
        q->next = p->next;
        p->next = q;
        p = q;
    }
    p->next = (*L)->next;
    (*L)->next->prior = p;
    return OK;
}


int main()
{
    DuLinkList L;
    DuLList_Init(&L);
    DuLList_Creat(&L);
    printf("双向链表中已经放入了26个英文字母.\n");
    printf("输出双向链表中的元素: ");
    DuLList_Traver(&L);
    printf("\n");
}



