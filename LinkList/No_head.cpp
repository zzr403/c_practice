#include <stdio.h>
#include <cstdlib>

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
/*
����LintList��LNode����ͬ���÷�
����LinkList����ǿ������һ��������
LNode����ǿ������һ���ڵ�
*/
bool InitList(LinkList &L)
{
    L = NULL; //��ʾ�����ձ���ֹ����������
    return true;
}
int main()
{
    LinkList L, pMove; //LinkList����һ��ָ�������ָ��
    InitList(L);

    pMove = L->next; //L.nextΪͷ���ĵ�ַ����������������������������һ��ͷ���L�����½��˽ڵ㣬����ֵ��L,����L->nextΪͷ����next��ָ����һ���ڵ�ĵ�ַ
    while (pMove)    //������������һ���ڵ��nextΪNULL�����Ե������һ���ڵ�ֵΪ�գ��˳�ѭ��
    {
        printf("����:%d\n", pMove->data); //�����ʱ��������ݣ�������ָ�����ͷ�������ô��������������һ���ڵ������
        pMove = pMove->next;              //����pMove�Ѿ�Ϊͷ�����һ���ڵ�ĵ�ַ�������������λ������һ���ڵ�ĵ�ַ���ڼ�������ѭ����ֱ��ָ��ĵ�ַΪ�գ�����ѭ����
    }
    printf("\n");

    system("pause");
    return 0;
}