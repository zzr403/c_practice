#include <stdio.h>
#include <cstdlib>
void test(int &x)
{
    x = 1024;
    printf("test内部函数x=%d\n", x);
}
int main()
{
    int x = 1;
    printf("调用test前 x=%d\n", x);
    test(x);
    printf("调用test后 x=%d\n", x);
    system("pause");
    return 0;
}