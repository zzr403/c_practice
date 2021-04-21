#include <stdio.h>
#include <cstdlib>
int main()
{

    int p, m;
    p = 102;
    m = 110;
    int *n;
    printf("p=%d\n", p);
    printf("&p=%p\n", &p);
    printf("m=%d\n", m);
    printf("&m=%p\n", &m);
    n = &m;
    printf("n=%d\n", *n);
    printf("n=%p\n", n);
    printf("p=%d\n", m);
    printf("p=%p\n", &m);

    printf("p=%d\n", *&p);
    printf("p=%d\n", &*&p);
    system("pause");
    return 0;
}