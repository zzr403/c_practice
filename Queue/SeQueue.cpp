#include <stdio.h>
#include <cstdlib>
#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int front, rare; //����Ϊһͷ��һͷ��������Ҫ��������ָ�룬�ֱ�ָ��ͷ��β
} SqQueue;

void InitQueue(SqQueue &Q) //�Զ��н��г�ʼ��
{
    Q.rare = Q.front = 0;
}

bool EnQueue(SqQueue &Q, int m)
{
    if ((Q.rare + 1) % MaxSize == Q.front) //������˼�ǵ�ȡģ��Ϊ��ͷ��ֵ���൱���ӱ�ת��һȦ��ȥ�ˣ������ͷ�г��ӵģ����Զ�ͷָ�벻��һֱ��0��
        return false;                      //������������
    Q.data[Q.rare] = m;                    //��m���뵽��β   �����βָ��һֱָ�������ݵ���һλ����������Ϊ��ʱ����ͷ��ָ��0�������Ȳ������ݣ�����λ
    Q.rare = (Q.rare + 1) % MaxSize;       //����βָ��������һλ,Ȼ��ȡģ
                                           //�������ڶ���һֱ��Ӷ�β����Ԫ�أ���ͷ����Ԫ�أ��൱��һ��һֱǰ����״̬�����ǵ���β���ﾡͷ���Ҷ�ͷ��������Ԫ���п�λ�ã��ٴδӶ�ͷ���������
                                           //ȡģ��ԭ���������൱��һ��������ͬ����Ȧ��
                                           //��MaxSizeΪ10������Ϊָ���Ѿ��ܵ�17���ˣ�ȡģ�Ļ�Ϊ7���൱��ת��һȦ�ٴε�7
    return true;
}

bool DeQueue(SqQueue &Q)
{
    if (Q.rare == Q.front)
        return false;                  //ջ�գ�����
    Q.front = (Q.front + 1) % MaxSize; //������˼�ǽ���ͷָ����ƾͿ��������Ӳ�����
    return true;
}
bool GetQueue(SqQueue &Q)
{
    if (Q.rare == Q.front)
        return false;                  //ջ�գ�����
    Q.front = (Q.front + 1) % MaxSize; //������˼�ǽ���ͷָ����ƾͿ��������Ӳ�����
    return true;
}
bool QueueEmpty(SqQueue &Q)
{
    if (Q.rare == Q.front)
        return true;
    else
        return false;
}

int main()
{
    SqQueue Q;
    system("pause");
    return 0;
}
