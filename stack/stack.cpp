#include <stdio.h>
#include <cstdlib>
#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int top; //top��ջ��ָ��
} SqStack;

void InitStack(SqStack &S) //��ջ���г�ʼ��
{
    S.top = -1; //�����൱��һ������ָ�룬���Կ���Ϊ0�����ǵ������±�Ϊ0�൱�������е�һ�����ݣ����⽫ָ��-1Ϊ��ջ
}

bool Push(SqStack &S, int m)
{
    if (S.top == MaxSize - 1)
        return false; //ջ��������
    S.top = S.top + 1;
    S.data[S.top] = m; //����д�� S.data[++S.top] = m;��������д��S.data[S.top++] = m
    return true;
}

bool Pop(SqStack &S)
{
    if (S.top == -1)
        return false; //ջ�գ�����
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
