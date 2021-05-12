#include <stdio.h>
#include <cstdlib>
#define MaxSize 10
typedef struct LinkNode //�ȶ���һ������ṹ�壬�ڲ������ݺ�ָ��
{
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{                           //���ﶨ��һ�����нṹ�壬�ڲ�������ͷָ��Ͷ�βָ��
    LinkNode *front, *rear; //���������ǲ�ָ��������ֱ�Ӷ���ṹ�����
} LinkQueue;

void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool IsEmply(LinkQueue Q)
{
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}
void EnQueue(LinkQueue *Q, int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q->rear->next = s; //�½ڵ���뵽rare��
    Q->rear = s;//�޸ı�βָ��
}

void testLinkQueue()
{
    LinkQueue Q;
    InitQueue(Q);
}