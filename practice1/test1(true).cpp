#include <stdio.h>
#include <cstdlib>
#include <string.h>
int main()
{
    int a, b;
    printf("������һ����:");
    scanf("%d", &a);
    char str2[30];
    int i = 1;
    while (a > 0)
    {
        if (i != 1)
        {
            strcat(str2, {" "});
        }
        i++;
        b = a;
        b = b % 10;
        a = a / 10;
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

    system("pause");
    return 0;
}
