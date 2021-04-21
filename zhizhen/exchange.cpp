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
    printf("请输入三个要比较大小的数：\n");
    scanf("%d,%d,%d", &a, &b, &c);
    printf("现在的x，y，z是：%d,%d,%d\n", a, b, c);
    printf("现在的x，y，z的地址是：%p,%p,%p\n", &a, &b, &c);
    Exchange(&a, &b, &c);
    printf("最新的x，y，z是：%d,%d,%d\n", a, b, c);
    printf("最新的x，y，z的地址是：%p,%p,%p\n", &a, &b, &c);
    system("pause");
    return 0;
}