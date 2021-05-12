#include <stdio.h>
#include <cstdlib>

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
/*
现在LintList与LNode是相同的用法
但是LinkList用来强调这是一个单链表
LNode用来强调这是一个节点
*/
bool InitList(LinkList &L)
{
    L = NULL; //表示建立空表，防止出现脏数据
    return true;
}
int main()
{
    LinkList L, pMove; //LinkList声明一个指向单链表的指针
    InitList(L);

    pMove = L->next; //L.next为头结点的地址，由于上述函数定义了先生成了一个头结点L，并新建了节点，返回值是L,所以L->next为头结点的next，指向下一个节点的地址
    while (pMove)    //由于链表的最后一个节点的next为NULL，所以当到最后一个节点值为空，退出循环
    {
        printf("链表:%d\n", pMove->data); //输出此时链表的内容，如智商指向的是头结点吗，那么现在内容则是县一个节点的内容
        pMove = pMove->next;              //以上pMove已经为头结点下一个节点的地址，而这里进行移位，到下一个节点的地址，在继续进行循环，直到指向的地址为空，跳出循环。
    }
    printf("\n");

    system("pause");
    return 0;
}