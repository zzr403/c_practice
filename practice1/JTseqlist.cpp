#include <stdio.h>
#include <cstdlib>
#define MaxSize 10 //������󳤶�
typedef struct
{
    int data[MaxSize]; // �þ�̬����������Ԫ��
    int length;        //˳���ǰ����
} SqList;

void InitList(SqList &L)
{
    //for (int i = 0; i < MaxSize; i++)
    //    L.data[i] = 0; //������Ԫ������Ĭ�ϳ�ʼֵ
    L.length = 0;      //˳�����Ϊ0
}

int main()
{
    SqList L;    //����һ��˳���
    InitList(L); //��ʼ��˳���
    //......
    //������ñ�ĳ���Ϊ6
    L.length=6;
    ///////////////////////////////////
    for (int i = 0; i < L.length; i++)
        printf("data[%d]=%d\n", i, L.data[i]);
    system("pause");
    return 0;
}