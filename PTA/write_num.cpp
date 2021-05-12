#include <stdio.h>
#include <cstdlib>
#include <string.h>
int MIN(int x, int n)
{
    int R = 1;
    for (int i = 1; i <= n; i++)
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
    scanf("%d", &n);
    if (n > MIN(10, 100) || n < 0)
        return false;


    int m;
    m = HE(n);
    printf("%d", m);
/*
    int b;
    char str2[30];
    int i = 1;
    while (m > 0)
    {
        if (i != 1)
        {
            strcat(str2, {" "});
        }
        i++;
        b = m;
        b = b % 10;
        m = m / 10;
        switch (b)
        {
        case 0:
            strcat(str2, {"ling"});
            break;
        case 1:
            strcat(str2, {"yi"});
            break;
        case 2:
            strcat(str2, {"er"});
            break;
        case 3:
            strcat(str2, {"san"});
            break;
        case 4:
            strcat(str2, {"si"});
            break;
        case 5:
            strcat(str2, {"wu"});
            break;
        case 6:
            strcat(str2, {"liu"});
            break;
        case 7:
            strcat(str2, {"qi"});
            break;
        case 8:
            strcat(str2, {"ba"});
            break;
        case 9:
            strcat(str2, {"jiu"});
            break;
        }
    }
    printf("%s", str2);
*/
    system("pause");
    return 0;
}