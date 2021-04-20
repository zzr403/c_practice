#include <stdio.h>
#include <cstdlib>
#define InitSize 10 //Ĭ����󳤶�
typedef struct
{
    int *date;   //ָʾ��̬���������ָ��
    int maxSize; //˳�����������
    int length;  //˳���ĵ�ǰ����
} SeqList;

void InitList(SeqList &L)
{
    L.date = (int *)malloc(sizeof(int) * InitSize); //��malloc��������һƪ�����Ĵ洢�ռ�
    L.length = 0;
    L.maxSize = InitSize;
}

void IncreaseSize(SeqList &L, int len) //���Ӷ�̬����ĳ���
{
    int *p = L.date;
    L.date = (int *)malloc(sizeof(int) * (L.maxSize + len));
    for (int i = 0; i < L.length; i++)
    {
        L.date[i] = p[i]; //�����ݸ��Ƶ�������
    }
    L.maxSize = L.maxSize + len; //˳�����󳤶�����len
    free(p);                     //�ͷ�ԭ���ڴ�ռ�
}

int main()
{
    SeqList L;   //����һ��˳���
    InitList(L); //��ʼ��˳���
                 //��˳����������뼸��Ԫ��
    printf("˳������󳤶�Ϊ��%d\n", L.maxSize);
    printf("����˳���ĳ���Ϊ��%d\n", L.length);

    IncreaseSize(L, 5);
    printf("��˳������󳤶�Ϊ��%d\n", L.maxSize);
    system("pause");
    return 0;
}