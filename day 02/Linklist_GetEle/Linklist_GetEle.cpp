/*
 * 实现单链表的取值操作
 * 2020/10/14
 * fyj
 */

#include <iostream>
using namespace std;


#define OK 1
#define ERROR -1

typedef int Status;
typedef struct LNode
{
    char data;
    struct LNode* next;
} LNode, *LinkList;

void InitLinkList()
{

}

void CreatLinkList(LinkList &L,int n)
{
    LNode *p;
    L = new LNode;
    L->next = NULL;
    for (int i = 0; i < n; ++i)
    {
        p = new LNode;
        std::cin>>p->data;
        p->next = L->next;
        L->next = p;
    }
}

Status GetElem(LinkList &L, int num,char &e)
{
    LinkList p;
    p = L->next;
    int j = 1;
    while (p&&j<num)
    {
        p = L->next;
        j++;
    }
    if (!p || j > num)
    {
        return ERROR;
    }
}


int main()
{
    LinkList L;
    L->next = NULL;
    CreatLinkList(*L,7);
    printf("请输入需要打印的元素序号： ");
    int num;
    std::cin >> num;
    char *e;
    GetElem(*L,num,*e);
}
    

