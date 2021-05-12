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

LinkList List_HeadInsert(LinkList &L) //这里用LinkList强调这里是建立单链表
{
    LNode *s; //这里强调建立一个节点
    int x;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL; //这里生成了一个空节点，只有一个头结点，也如同列表最后一个数
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode)); //再次申请一个节点，s指的是一个指针
        s->data = x;                        //填入数据，插入的节点数据为输入的x
        s->next = L->next;                  //这里一个链表的最后一个元素是不止像任何元素的，所以最后一个节点的next项为空，本来在head上，现在有插入了一个节点，所以将head上的next的null放到新节点也就是s的next上
        L->next = s;                        //要将两个节点连接，所以头结点上的next不应该再为空，应该指向新节点的地址，当然这个新节点的地址为s
        scanf("%d", &x);                    //这里如同上一个scanf一样，这里在循环体内部，循环执行
    }
    return L;
}
int main()
{
    LinkList L, pMove; //LinkList声明一个指向单链表的指针

    List_HeadInsert(L); //插入链表
    pMove = L->next;    //L.next为头结点的地址，由于上述函数定义了先生成了一个头结点L，并新建了节点，返回值是L,所以L->next为头结点的next，指向下一个节点的地址
    while (pMove)       //由于链表的最后一个节点的next为NULL，所以当到最后一个节点值为空，退出循环
    {
        printf("链表:%d\n", pMove->data); //输出此时链表的内容，如智商指向的是头结点吗，那么现在内容则是县一个节点的内容
        pMove = pMove->next;              //以上pMove已经为头结点下一个节点的地址，而这里进行移位，到下一个节点的地址，在继续进行循环，直到指向的地址为空，跳出循环。
    }
    printf("\n");

    system("pause");
    return 0;
}