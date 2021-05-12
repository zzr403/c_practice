#include <stdio.h>
#include <cstdlib>
#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int top; //top是栈顶指针
} SqStack;

void InitStack(SqStack &S) //对栈进行初始化
{
    S.top = -1; //由于相当于一个数组指针，所以可以为0，但是当数组下表为0相当于数组中第一个数据，随意将指标-1为空栈
}

bool Push(SqStack &S, int m)
{
    if (S.top == MaxSize - 1)
        return false; //栈满，报错
    S.top = S.top + 1;
    S.data[S.top] = m; //可以写成 S.data[++S.top] = m;，不可以写成S.data[S.top++] = m
    return true;
}

bool Pop(SqStack &S)
{
    if (S.top == -1)
        return false; //栈空，报错
    S.top = S.top - 1;
    return true;
}

bool StackEmpty(SqStack &S)
{
    if (S.top == -1)
        return true;
    else
        return false;
}

int main()
{
    SqStack S;
    InitStack(S);
    system("pause");
    return 0;
}
