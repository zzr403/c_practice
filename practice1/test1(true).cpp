#include <stdio.h>
#include <cstdlib>
void test(int &x)
{
    x = 1024;
    printf("test�ڲ�����x=%d\n", x);
}
int main()
{
    int x = 1;
    printf("����testǰ x=%d\n", x);
    test(x);
    printf("����test�� x=%d\n", x);
    system("pause");
    return 0;
}