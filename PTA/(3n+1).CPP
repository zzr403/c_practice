#include <stdio.h>
 
int main()
{
 int n;
    int i = 0;
    if(scanf("%d", &n)){}
    do
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        { 
            n = (3 * n + 1) / 2;
        }
        i++;
    } while (n != 1);
    printf("%d\n", i);


    system("pause");
    return 0;
}