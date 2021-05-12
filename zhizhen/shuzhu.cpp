#include <stdio.h>
#include <cstdlib>
int main()
{
    int a[10] = {2, 5, 4, 7, 8, 6, 8, 47, 5, 6};
    /*
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    */
    //a[10] = {2, 5, 4, 7, 8, 6, 8, 47, 5, 6};
    for (int i = 0; i < 10; i++)
    {
        printf("a[%d]=%d;   a[%d]的地址是%p\n", i, a[i], i, &a[i]);
    }
    printf("\n");
    for (int i = 0; i < 9; i++)
    {
        if (a[i + 1] > a[i])
        {
            int p;
            p = a[i + 1];
            a[i + 1] = a[i];
            a[i] = p;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("a[%d]=%d;   a[%d]的地址是%p\n", i, a[i], i, &a[i]);
    }
    system("pause");
    return 0;
}
