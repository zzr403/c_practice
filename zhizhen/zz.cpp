#include <stdio.h>
#include <cstdlib>
int main()
{
    int a[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8};
    printf("%d\n", a[2]);
    printf("%p\n", &a[2]);
    printf("%d\n", a[3]);
    printf("%p\n", &a[3]);
    printf("%d\n", sizeof(a) / 10);
    int *p;
    p = &a[2];
    p++;
    printf("%p\n", p);
    printf("%d\n", *p);
    system("pause");
    return 0;
}