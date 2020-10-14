/*
 * 用户手动输入数据，创建一个线性表，从键盘获取用户输入，实现插入此元素到线性表的指定位置
 * 2020/10/14
 * fyj
*/

#include <iostream>
#define MAXSIZE 50

typedef struct {        //线性表的抽象数据类型
    int data[MAXSIZE];
    int length;
} Sqlist;

Sqlist list;   //定义一个线性表list
Sqlist list_modify;  //用于保存插入元素后的list

void InitList(Sqlist L)  //初始化一个线性表，将其长度置为0
{
    L.length = 0;
}

int GetElem(Sqlist L, int i)   //获取第i个元素
{
    return L.data[i];
}

int ListLength(Sqlist L)     // 打印字符串的长度    
{
    return L.length;
}

void ListInsert(Sqlist L, int position, char elem_insert)         //插入元素到指定位置position
{
    if (position <= L.length) {         // position以排除不会小于等于0
        for (int i = L.length; i >= position; i--)   // 插入元素后，插入位置后的所有元素向后平移一位
        {
            L.data[i] = L.data[i - 1];
        }
        L.data[position - 1] = elem_insert;
    }
    else if (position == L.length + 1)      //插入到字符串末尾
    {
        L.data[position - 1] = elem_insert;
    }
    list_modify = L;         // 使用list_modify保存修改后的字符串
}

void List_show(Sqlist L)       // 打印字符串
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
    printf("请输入元素插入的位置序号(1-%d): ", list.length + 1);
    int num;
    std::cin >> num;


    while (true) {
        if (num > list.length + 1 || num <= 0)  // 用户输入的插入位置序号小于等于0或者大于字符串长度+1，都会要求用户重新输入位置序号
        {
            printf("序号输入有误！\n");
            printf("请重新输入元素插入的位置序号(1-%d): ", list.length + 1);
            std::cin >> num;
        }
        else if (1 <= num <= list.length + 1) {       // 插入的位置序号合理，执行插入函数操作
            char element;
            printf("请输入待插入的元素: ");
            std::cin >> element;
            list.length++;
            ListInsert(list, num, element);    // 插入元素到字符串
            printf("插入后字符串变为：");
            List_show(list_modify);          // 打印插入后已经修改的字符串
            break;
        }
    }
}




