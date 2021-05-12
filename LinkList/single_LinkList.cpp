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

LinkList List_HeadInsert(LinkList &L) //������LinkListǿ�������ǽ���������
{
    LNode *s; //����ǿ������һ���ڵ�
    int x;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL; //����������һ���սڵ㣬ֻ��һ��ͷ��㣬Ҳ��ͬ�б����һ����
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode)); //�ٴ�����һ���ڵ㣬sָ����һ��ָ��
        s->data = x;                        //�������ݣ�����Ľڵ�����Ϊ�����x
        s->next = L->next;                  //����һ����������һ��Ԫ���ǲ�ֹ���κ�Ԫ�صģ��������һ���ڵ��next��Ϊ�գ�������head�ϣ������в�����һ���ڵ㣬���Խ�head�ϵ�next��null�ŵ��½ڵ�Ҳ����s��next��
        L->next = s;                        //Ҫ�������ڵ����ӣ�����ͷ����ϵ�next��Ӧ����Ϊ�գ�Ӧ��ָ���½ڵ�ĵ�ַ����Ȼ����½ڵ�ĵ�ַΪs
        scanf("%d", &x);                    //������ͬ��һ��scanfһ����������ѭ�����ڲ���ѭ��ִ��
    }
    return L;
}
int main()
{
    LinkList L, pMove; //LinkList����һ��ָ�������ָ��

    List_HeadInsert(L); //��������
    pMove = L->next;    //L.nextΪͷ���ĵ�ַ����������������������������һ��ͷ���L�����½��˽ڵ㣬����ֵ��L,����L->nextΪͷ����next��ָ����һ���ڵ�ĵ�ַ
    while (pMove)       //������������һ���ڵ��nextΪNULL�����Ե������һ���ڵ�ֵΪ�գ��˳�ѭ��
    {
        printf("����:%d\n", pMove->data); //�����ʱ��������ݣ�������ָ�����ͷ�������ô��������������һ���ڵ������
        pMove = pMove->next;              //����pMove�Ѿ�Ϊͷ�����һ���ڵ�ĵ�ַ�������������λ������һ���ڵ�ĵ�ַ���ڼ�������ѭ����ֱ��ָ��ĵ�ַΪ�գ�����ѭ����
    }
    printf("\n");

    system("pause");
    return 0;
}