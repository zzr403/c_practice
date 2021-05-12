#include <stdio.h>
#include <cstdlib>
#include <string.h>
int MIN(int x, int n)
{
    long int R = 1;
    for (int i = 0; i < n; i++)
    {
        R = R * x;
    }
    return R;
}

int HE(int m)
{
    int n = 0, k;
    while (m > 10)
    {
        k = m;
        m = m / 10;
        k = k % 10;
        n = n + k;
    }
    n = n + m;
    return n;
}

int main()
{
    int n;
    //scanf("%d", &n);
    printf("%d\n", MIN(10, 10));
    // if (n > MIN(10, 100) || n < 0)
    {
        //   return false;
    }

    int m;
    m = HE(n);
    printf("%d", n);

    system("pause");
    return 0;
}