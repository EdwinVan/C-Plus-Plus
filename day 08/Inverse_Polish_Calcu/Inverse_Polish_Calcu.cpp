// 使用链栈，实现输入逆波兰表达式，输出计算结果
// 2020/10/20
// fyj

#include <iostream>
#include "stdlib.h"
#include "ctype.h"

#define OK 1
#define True 1
#define False -1
#define ERROR 0
#define Status int
#define ElemType double 
#define MAXBUFFER 10

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

Status LinkStack_init(LinkStack s)        // 链栈初始化
{
    s.top = (StackNode*)malloc(sizeof(StackNode));
    if (!s.top) return ERROR;
    s.top = NULL;
    s.count = 0;
    return OK;
}

Status Push(LinkStack &s,double e)    // 入栈操作
{
    StackNode* p;
    p = (LinkStackPtr)malloc(sizeof(StackNode));
    if (!p) return ERROR;
    p->data = e;
    p->next = s.top;
    s.top = p;
    s.count++;
    return OK;
}

Status Pop(LinkStack &s, double &e)   // 出栈操作
{
    LinkStackPtr p;
    p=(LinkStackPtr)malloc(sizeof(StackNode));
    if(!p) return ERROR;
    e = s.top->data;
    s.top = s.top->next;
    s.count--;
    free(p);
    return OK;
}

int main()
{
    LinkStack s;
    LinkStack_init(s);  // 初始化链栈
    char c;
    char str[MAXBUFFER];
    int i = 0;
    double d,e;
    
    printf("请输入逆波兰表达式，以空格分隔操作数以及操作符，#符号作为结束标志\n");
    printf("逆波兰表达式->> ");
    scanf("%c",&c);
    
    while (c!='#')
    {
        while(isdigit(c) || c=='.')  // 读取数字
        {
            str[i++] = c;
            str[i] = '\0';
            if(i>= MAXBUFFER)
            {
                printf("出错，输入的单个数字过大！\n");
                return -1;
            }
            scanf("%c",&c);

            if(c == ' ')
            {
                d = atof(str);  // 将字符串中数字转化为浮点型数字
                Push(s,d);
                i=0;
                break;
            }
        }
        switch (c)
        {
            case '+':
                Pop(s,d);
                Pop(s,e);
                Push(s,d+e);
                break;
            case '-':
                Pop(s,d);
                Pop(s,e);
                Push(s,e-d);
                break;
            case '*':
                Pop(s,d);
                Pop(s,e);
                Push(s,e*d);
                break;
            case '/':
                Pop(s,d);
                Pop(s,e);
                if (d == 0) 
                {
                    printf("除数不能为0，程序出错！\n");
                    return ERROR;
                }
                else Push(s,e/d);
                break;
        }
        scanf("%c",&c);
    }
    double result;
    Pop(s, result);
    printf("表达式结果为: %f\n",result);
}
