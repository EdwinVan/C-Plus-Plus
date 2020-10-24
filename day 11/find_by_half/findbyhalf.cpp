// 递归实现折半查找,在已知数组中查找待查数据
// 2020-10-24
// fyj

#include <iostream>

#define num 89  // 待查找的数据
int data[12] = {0,1,1,2,3,5,8,13,21,34,55,89} ;  // 已知数组

void Find(int low,int mid,int high)
{
    if(high>low && data[mid] < num) 
    {
        low = mid + 1;
        mid = (low + high) / 2;
        Find(low,mid,high);
    }
    else if(high>low && data[mid] > num)
    {
        high = mid - 1;
        mid = (low + high) / 2;
        Find(low,mid,high);
    }
    else if(data[mid] == num) { 
        printf("在数组中找到了%d",num);
        printf("在数组中第%d个位置\n",mid+1);
    }
    else 
    {
        printf("在数组中没找到%d",num);
        return exit(0);
    }
}

int main()
{
    int low=0,high=11,mid=(low+high) / 2; 
    Find(low,mid,high);
}