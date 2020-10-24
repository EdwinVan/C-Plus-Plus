// 输出实现n阶汉诺塔的步骤
// 2020-10-24
// fyj

#include <iostream>

void hanoi_tower(int n,char x,char y,char z)
{
    if(n==1) {printf("%c---->%c\n",x,z);}
    else
    {
        hanoi_tower(n-1,x,z,y);
        printf("%c---->%c\n",x,z);
        hanoi_tower(n-1,y,x,z);
    }
}


int main()
{
    int n;
    printf("请输入汉诺塔的阶数: ");
    scanf("%d",&n);
    printf("汉诺塔步骤如下: \n");
    hanoi_tower(n,'x','y','z');
}