#include <stdio.h>
#include <cstdlib>
int main()
{

    int i;
    int j;
    char k;
    int *p1;
    i = 1;
    j = 5;
    k = 'hello';
    p1 = &i;
    printf("i=%d,j=%d,k=%x\n", i, j, k);
    printf("i=%p,j=%o,k=%d\n", &i, &j, &k);
    printf("i=%p", p1);
    system("pause");
    return 0;
}