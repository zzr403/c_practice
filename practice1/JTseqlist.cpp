#include <stdio.h>
#include <cstdlib>
#define MaxSize 10 //定义最大长度
typedef struct
{
    int data[MaxSize]; // 用静态数组存放数据元素
    int length;        //顺序表当前长度
} SqList;

void InitList(SqList &L)
{
    //for (int i = 0; i < MaxSize; i++)
    //    L.data[i] = 0; //将所有元素设置默认初始值
    L.length = 0;      //顺序表长度为0
}

int main()
{
    SqList L;    //声明一个顺序表
    InitList(L); //初始化顺序表
    //......
    //如果设置标的长度为6
    L.length=6;
    ///////////////////////////////////
    for (int i = 0; i < L.length; i++)
        printf("data[%d]=%d\n", i, L.data[i]);
    system("pause");
    return 0;
}