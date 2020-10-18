// 利用栈数据结构，用户输入一个2进制数，程序打印输出它的10进制形式
// 2020-10-18
// fyj


#include <iostream>
#include <stdlib.h>
#include <string>

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
    if(s.top - s.base == s.StackSize) exit(0);
    *s.top++ = e;
    return OK;
}


Status Stack_Creat(SqStack *s)               // 保存输入的2进制数
{
    printf("从左往右输入数字，数字9作为结束输入标志!\n");
    while(TRUE)
    {
        int num;
        scanf("%d",&num);
        if(num == 9){ break;}
        else if(num <0 || num >1 ) { printf("输入有误，请重新输入此位数字: "); }          // 输入的数字不得大于1或者不得小于0
        else { 
            Push(*s,num); 
        }
    }
    return OK;
}

Status Pop(SqStack s, ELemType *e,int i)     // 出栈操作
{
    for(int j=0;j<i+1;j++)
    {
        s.top--;
        *e= *s.top;
    }
    
    return OK;
}

int index(int e,int x)                     // 指数运算
{
    int num;
    num = e;
    if(x==0) return 1;
    else if(x==1) return 2;
    else
    {
        for (int i = 0;i<x-1;i++)
        {
            num = num * 2;
        }
        return  num;
    }
}

int main()
{
    SqStack s;       
    Stack_Init(&s);                       // 栈的初始化
    printf("请输入2进制数: ");
    Stack_Creat(&s);                      // 读取2进制数

    int result = 0;
    int stacksize = s.top - s.base;

    for(int i=0;i<stacksize;i++)         
    {
        ELemType e;
        Pop(s,&e,i);
        printf("第%d位是%d\n",stacksize-i,e);        
        result = result + e * index(2,i);     // 计算每个位上的指数结果总和
    }
    printf("输出10进制: %d",result);
}