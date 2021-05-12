#include <stdio.h>
#include <cstdlib>
typedef struct Node
{
    int data;
    struct Node *next;
} Node, *LinkList;

LinkList InsertList(LinkList &L)
{
    Node *s;
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
    printf("输入链表：");
    int x;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (Node *)malloc(sizeof(Node));
        s->next = L->next;
        L->next = s;
        s->data = x;
        printf("输入链表：");
        scanf("%d", &x);
    }
    return L;
}

Node *GetNode(LinkList &L, int i)
{
    Node *p;
    p = L->next;
    int j = 1;
    while (j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

bool InsertLocate(LinkList &L, int x, int Pos)
{
    Node *s, *p;
    int j = 1;
    if (Pos < 1)
        return false;
    s = (Node *)malloc(sizeof(Node));
    p = L->next;
    while (p != NULL && j < Pos - 1)
    {
        p = p->next;
        j++;
    }

    s->data = x;
    s->next = p->next;
    p->next = s;
    return true;
}

LinkList PrintList(LinkList &L)
{
    Node *NMove;
    int length = 0;
    NMove = L->next;
    while (NMove)
    {
        printf("第%d个节点的内容是%d\n", length + 1, NMove->data);
        NMove = NMove->next;
        length++;
    }
    printf("链表长度是%d\n", length);
}

int main()
{
    LinkList L;
    InsertList(L);
    PrintList(L);
    printf("\n\n");
    InsertLocate(L, 23, 3);
    PrintList(L);

    Node *m;
    m = GetNode(L, 5);
    printf("%d\n", m->data);
    system("pause");
    return 0;
}
