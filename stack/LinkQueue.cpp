#include <stdio.h>
#include <cstdlib>
#define MaxSize 10
typedef struct LinkNode //先定义一个链表结构体，内部有数据和指针
{
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{                           //这里定义一个队列结构体，内部包含队头指针和队尾指针
    LinkNode *front, *rear; //而且这里是不指定类型名直接定义结构体变量
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
    Q->rear->next = s; //新节点插入到rare后
    Q->rear = s;//修改表尾指针
}

void testLinkQueue()
{
    LinkQueue Q;
    InitQueue(Q);
}