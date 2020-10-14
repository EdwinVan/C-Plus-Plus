/*
 * 用户手动输入字符串，程序将其保存以线性表形式保存，从键盘获取用户需要删除的元素位置序号，实现删除线性表指定位置的元素
 * 2020/10/14
 * fyj
*/

#include <iostream>
#define MAXSIZE 250

typedef struct {        //线性表的抽象数据类型
    int data[MAXSIZE];
    int length;
} Sqlist;

Sqlist list;   //定义一个线性表，保存读取的字符串
Sqlist list_modify;  //用于保存删除元素后的线性表

void InitList(Sqlist L)  //初始化一个线性表，将其长度置为0
{
    L.length = 0;
}

int ListLength(Sqlist L)     // 打印字符串的长度    
{
    return L.length;
}

void ListDelete(Sqlist L, int position)         //插入元素到指定位置position
{
    if (position <= L.length) {                 // 删除元素位置不在末尾，position已经排除不会小于等于0
        
        for (int i = position; i < L.length; i++)   // 删除元素后，删除位置后的所有元素向前平移一位
        {
            L.data[i-1] = L.data[i];
        }
        L.length--;
        list_modify = L;                        // 使用list_modify保存修改后的字符串
    }
    else if (position == L.length)              // 删除元素在字符串末尾
    {
        for (int i = 0; i < L.length-1; i++)   
        {
            list_modify.data[i] = L.data[i];    // 使用list_modify保存修改后的字符串
        }
    }
}



void List_show(Sqlist L)                        // 打印字符串
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%c", L.data[i]);
    }
    printf("\n");
}

int main()
{
    InitList(list);   //初始化一个线性表
    printf("请输入一串字符(结束输入标志为$)：");

    while (true) {
        char a;
        std::cin >> a;
        if (a == '$') {
            break;
        }
        list.data[list.length] = a;
        list.length++;
    }

    printf("你所输入的字符串为：");
    for (int i = 0; i < list.length; i++) {
        printf("%c", list.data[i]);
    }

    printf("\n");
    printf("这串字符的长度为%d", ListLength(list));       // 输出字符串长度
    printf("\n");
    printf("请输入删除元素的位置序号(1-%d): ", list.length);
    int num;
    std::cin >> num;

    while (true) {
        if (num > list.length || num <= 0)        // 用户输入的删除元素位置序号小于等于0或者大于字符串长度，都会要求用户重新输入位置序号
        {
            printf("序号输入有误！\n");
            printf("请重新输入删除元素的位置序号(1-%d): ", list.length);
            std::cin >> num;
        }
        else if (1 <= num <= list.length) {       // 插入的位置序号合理，执行插入函数操作
            ListDelete(list, num);                // 删除num位置的元素
            printf("删除后字符串变为：");
            List_show(list_modify);               // 打印删除元素后的字符串
            break;
        }
    }
}





