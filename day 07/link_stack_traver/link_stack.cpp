// 实现链栈的创建、读取某一位置的元素操作
// 2020/10/19
// fyj

#include <iostream>
#include <string>
#include "stdlib.h"
#include "string.h"

#define OK 1
#define True 1
#define False -1
#define ERROR 0
#define Status int
#define ElemType char

typedef struct StackNode
{
    ElemType data;
    struct StackNode* next;
} StackNode, * LinkStackPtr;

typedef struct
{
    LinkStackPtr top;  // 栈top指针
    int count;  // 栈元素计数器
} LinkStack;

Status LinkStack_init(LinkStack& s)
{
    s.top = (StackNode*)malloc(sizeof(StackNode));
    if (!s.top) return ERROR;
    s.top = NULL;
    s.count = 0;
    return OK;
}

Status LinkStack_Creat(LinkStack& s)
{
    for (int i = 0; i < 26; i++)
    {
        StackNode* p;
        p = (LinkStackPtr)malloc(sizeof(StackNode));
        if (!p) return ERROR;
        p->data = 'A' + i;
        p->next = s.top;
        s.top = p;
        s.count++;
    }
    return OK;
}

Status Pop(LinkStack& s, ElemType& e)   // 出栈操作
{
    StackNode* p;
    p = (LinkStackPtr)malloc(sizeof(StackNode));
    if (!p)  exit(0);
    // if(s.top->data == NULL) exit(0);
    e = s.top->data;
    s.top = s.top->next;
    s.count--;
    return OK;
}

int main()
{
    LinkStack s;
    LinkStack_init(s);  // 初始化链栈
    LinkStack_Creat(s);  // 将26个英文字母压入栈中
    printf("打印出栈中所有元素: \n");
    while (s.count > 0)
    {
        ElemType e;
        Pop(s, e); // 将栈顶元素的值出栈pop赋值给e
        printf("%c ",e);
    }
}
