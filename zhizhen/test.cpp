#include <stdio.h>
#define OK 0;
#include <windows.h>
#include <time.h>
#include <string.h>

int my_sum(int a, int b)
{
    return a + b;
}
int my_sub(int a, int b)
{
    return a - b;
}
int my_mul(int a, int b)
{
    return a * b;
}
int my_div(int a, int b)
{
    return a / b;
}
int my_get_max(int a, int b)
{
    return a > b ? a : b;
}
int my_get_min(int a, int b)
{
    return a < b ? a : b;
}
int main()
{
    printf("%d\n", my_sum(98, 100));     //求和
    printf("%d\n", my_sub(200, 50));     //减法
    printf("%d\n", my_mul(50, 40));      //乘法
    printf("%d\n", my_div(10, 5));       //除法
    printf("%d\n", my_get_max(100, 60)); //求最大值
    printf("%d\n", my_get_min(40, 20));  //求最小值
    system("pause");
    return OK;
}
