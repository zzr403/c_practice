#include <stdio.h>
#include <cstdlib>
struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node node1 = {2, NULL};
    struct Node node2 = {3, NULL};
    struct Node node3 = {4, NULL};
    struct Node *P;

    node1.next = &node2;
    node2.next = &node3;
    printf("%d", node1.next);
    system("pause");
    return 0;
}
