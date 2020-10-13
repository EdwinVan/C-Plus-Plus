/*
 * 用户手动输入数据，保存到线性表中，实现读取一段线性表的第i个数据元素
 * 2020/10/13
 * fyj
*/

#include <iostream>
#define MAXSIZE 50

typedef struct {        //线性表的抽象数据类型
    int data[MAXSIZE];
    int length;
} Sqlist;

Sqlist list;   //定义一个线性表list

void InitList(Sqlist L)  //初始化一个线性表，将其长度置为0
{
    L.length = 0;
}

int GetElem(Sqlist L,int i)   //获取第i个元素
{
    return L.data[i];
}

int ListLength(Sqlist L)
{
    return L.length;
}

int main()
{
    InitList(list);   //初始化一个线性表
    printf("请输入一串字符(结束输入标志为$)：");

    while(true) {
        char a;
        std::cin >> a;
        list.data[list.length] = a;
        list.length++;
        if (a == '$') { break; }
    }

    printf("你所输出的线性表为：");
    for (int i = 0; i < list.length-1; i++) {
        printf("%c", list.data[i]);
    }
    printf("\n");
    printf("线性表的长度为%d",ListLength(list)-1); //输出的为length-1,因为$占一位
    printf("\n");
    printf("请输入你要打印的元素序号: ");

    int num;
    std::cin >> num;

    while (true) {
        
        
        if (num > list.length)
        {
            printf("序号输入有误！\n");
            printf("请重新输入你要打印的元素序号: ");
            std::cin >> num;
        }
        else {
            char element;
            element = GetElem(list, num - 1);

            printf("第%d个Element是%c\n", num, element);
            break;
        }
    }
}

