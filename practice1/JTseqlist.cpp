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
    for (int i = 0; i < MaxSize; i++)
        L.data[i] = 0; //������Ԫ������Ĭ�ϳ�ʼֵ
    //L.length = 0;      //˳�����Ϊ0
}
//����Ԫ��
/*�����������βΣ���һ����L���ݣ��ڶ����ǲ���Ԫ�ص�λ��i���������ǲ��������e
����Ԫ��������˵Ҫ���Ǽ�������
1.���ݳ��Ȼᷢ���仯��Ҳ����L.length������
2.��iλ�ò���һ��Ԫ�أ��������λ�ú��汾����Ԫ�ػ��������
3.iλ�û��һ���µ�Ԫ��
*/

/*�����ڲ���ǰҪ����һЩ�ж�
1.Ҫ��֤����Ԫ�ص���ȷ�ԣ�������
2.������MaxSizeΪ10�����Ǵ�ʱ���ǵ�L.lengthΪ5������Ҫ���������ڵ�7��λ�ò���һ�����ݣ���Ȼ���ܳɹ��ˣ����ǲ���һ��6λ�ã���������һ���ϸ��˳�����
3.��������Ѿ��洢���ˣ���ô�ڴ洢Ҳһ���ᷢ������
4.Ҫ�������һ���жϣ��ɹ�������ʾ
*/
bool ListInsert(SqList &L, int i, int e)
{
    //�ж�1�������i����Ҫ��
    if (i < 1 || i > L.length + 1)
        return false;
    //�ж�2���洢�ռ��Ƿ����
    if (L.length >= MaxSize)
        return false;
    //��û�����ⰴһ�²�����ʽִ��
    for (int j = L.length; j >= i; j--)
    {                              //jΪ���ݵĸ���������i��λ�ü�һ���µ�������ô��i-���һ������������ƶ�һλ�����Զ������Χ�ڵ������д���
        L.data[j] = L.data[j - 1]; //�����ݺ���һλ
    }
    L.data[i - 1] = e; //��i�ϲ���һ���µ�����
    L.length++;
    return true; //���ȼ�1
}
/*������һ��Ҫ��Ҫע�⣬κ��������±��ǲ�ͬ�ģ������±��0��ʼ��λ���1��ʼ
���Լ���L.length=6,�����λ���ڵ�����
��ôj�ĳ�ʼֵΪ6,6>=3...
����һ�����   L.data[j] = L.data[j - 1]; ���� L.data[6] = L.data[5]
��˼�ǽ���6�����ݷŵ���7��λ�ã�������û��ģ�Ҫ�����µ�ɾ������Ӧ������һ���ص�
*/
/*����������һ�����⣬�Ұ��ղ����˼·д������������������к��ֽ�����ԣ������о������뽫�����Ԫ�غ��ƣ�10->11,9->10,8->7
�Ұ������˼·ɾ������ǰ�ƣ�Ҳ����10->9,9->8,8->7,����������ʵ���ƶ���һ������10->9->8->7...
����Ӧ����4->3,5->4,6->5������*/
bool ListDelete(SqList &L, int i)
{
    //�ж�1�������i����Ҫ��
    if (i < 1 || i > L.length + 1)
        return false;
    //����Ҫɾ��Ԫ�ص�ֵ
    int e;
    e = L.data[i - 1]; //Ҫɾ�����ǵڳ�����Ԫ�أ��������������Ǵ�0��ʼ������Ҫ��һ��1
    //��û�����ⰴһ�²�����ʽִ��
    //////////////////////////////////////////////////////////////////
    /*   for (int j = L.length - 1; j > i; j--)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    printf("ɾ����Ԫ����%d\n", e);
    return true;
    */
    ////////////////////////////////////////////////////////////////////
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

//�����ǰ�ֵ����
int LocateElemV(SqList L, int e)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}
int LocateElemW(SqList L, int i)
{
    int *p;
    p = &L.data[0];
    for (int j = 1; j < i; j++)
    {
        p++;
    }
    return *p;
}

bool MinDelete(SqList &L)
{
    int m = L.data[0];
    int n;
    if (L.length == 0)
        return false;
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] < m)
        {
            m = L.data[i];
            n = i;
        }
    }
    L.data[n] = L.data[L.length - 1];
    L.length--;
    return true;
}



int main()
{
    SqList L; //����һ��˳���
    L.length = 5;

    for (int i = 0; i < L.length; i++)
        printf("δ��ʼ��֮ǰ��data[%d]=%d\n", i, L.data[i]);
    printf("length=%d\n", L.length);
    printf("+----------------------�ָ�---------------------------------+\n");

    InitList(L); //��ʼ��˳���

    for (int i = 0; i < L.length; i++)
        printf("���г�ʼ�����data[%d]=%d\n", i, L.data[i]);
    printf("length=%d\n", L.length);

    printf("+----------------------�ָ�---------------------------------+\n");
    ListInsert(L, 1, 4);
    ListInsert(L, 2, 1);
    ListInsert(L, 3, 7);
    ListInsert(L, 4, 3);
    ListInsert(L, 5, 2);

    printf("������length=%d\n", L.length);
    for (int i = 0; i < L.length; i++)
        printf("�����ĵ�data[%d]=%d\n", i, L.data[i]);

    printf("+----------------------�ָ�---------------------------------+\n");
    ListDelete(L, 6);
    ListDelete(L, 6);
    ListDelete(L, 6);
    ListDelete(L, 6);
    ListDelete(L, 6);
    printf("ɾ����length=%d\n", L.length);
    for (int i = 0; i < L.length; i++)
        printf("ɾ����ĵ�data[%d]=%d\n", i, L.data[i]);

    printf("+----------------------�ָ�---------------------------------+\n");
    printf("���￴һ��ÿ��Ԫ�صĵ�ַ\n");
    for (int i = 0; i < L.length; i++)
        printf("��%d��Ԫ�صĵ�ַ��%p\n", i + 1, &L.data[i]);
    printf("+----------------------��ֵ����---------------------------------+\n");
    //��ֵ����
    int locateV;
    locateV = LocateElemV(L, 5);
    printf("Ԫ�ص�λ����=%d\n", locateV);
    printf("+----------------------�ְ�λ����---------------------------------+\n");
    //��ֵ����
    int locateW;
    locateW = LocateElemW(L, 4);

    printf("Ԫ����=%d\n", locateW);

    printf("+----------------------ɾ����Сֵ�������һλ�滻---------------------------------+\n");
    //��ֵ����
    MinDelete(L);
    for (int i = 0; i < L.length; i++)
        printf("ɾ����ĵ�data[%d]=%d\n", i, L.data[i]);
    system("pause");
    return 0;
}