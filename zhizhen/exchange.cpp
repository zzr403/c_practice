#include <stdio.h>
#include <cstdlib>

void swap(int *x, int *y)
{
    int *p;
    *p = *x;
    *x = *y;
    *y = *p;
}

void Exchange(int *x, int *y, int *z)
{

    if (*x > *y)
        swap(x, y);
    if (*x > *z)
        swap(x, z);
    if (*y > *z)
        swap(y, z);
}

int main()
{
    int a;
    int b;
    int c;
    printf("����������Ҫ�Ƚϴ�С������\n");
    scanf("%d,%d,%d", &a, &b, &c);
    printf("���ڵ�x��y��z�ǣ�%d,%d,%d\n", a, b, c);
    printf("���ڵ�x��y��z�ĵ�ַ�ǣ�%p,%p,%p\n", &a, &b, &c);
    Exchange(&a, &b, &c);
    printf("���µ�x��y��z�ǣ�%d,%d,%d\n", a, b, c);
    printf("���µ�x��y��z�ĵ�ַ�ǣ�%p,%p,%p\n", &a, &b, &c);
    system("pause");
    return 0;
}