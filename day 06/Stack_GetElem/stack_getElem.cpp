// 创建一个栈，存入26个英文字母，用户输入数字，程序输出相应数量的元素
// 2020-10-18
// fyj

#include <iostream>

#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define Status int
#define ELemType char
#define StackMaxSize 50

typedef struct 
{
    ELemType * base;
    ELemType * top;
    int StackSize;
} SqStack;

Status Stack_Init(SqStack *s)
{
    s->base = (ELemType *) malloc (StackMaxSize * sizeof(ELemType));
    if(!s->base) return ERROR;
    s->top = s->base;
    s->StackSize = StackMaxSize;
    return OK;
}

Status Push(SqStack &s, ELemType e)
{
    if(s.top - s.base == s.StackSize) return ERROR;
    *s.top++ = e;
    return OK;
}


Status Stack_Creat(SqStack *s)
{
    for(int i=0;i<26;i++)
    {
        char elem;
        elem = 'A' + i;
        Push(*s,elem);
    }
    return OK;
}

Status Pop(SqStack s, ELemType e,int i)
{
    s.top --;
    for (int j =0;j<i;j++)
    {
        if(s.top == s.base) return ERROR;
        s.top --;
    }
    e=*(s.top); 
    printf("%c   ",e);
    return OK;
}

int main()
{
    SqStack s;
    Stack_Init(&s);
    Stack_Creat(&s);
    printf("亲输入你想要输出的元素个数: ");
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        ELemType e;
        Pop(s,e,i);
    }
}