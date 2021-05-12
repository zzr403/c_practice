//求平均值
#include <stdio.h>
#include <cstdlib>
#include <string.h>

bool check(char a[], int n)
{
    for (int i = 0; i < n; i++)
    {
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    char a[50][50];
    for (int i = 0; i < N; i++)
        scanf("%s", &a[i]);
    for (int i = 0; i < N; i++)
    {
        printf("第%d个值是%s,字符个数%d", i, a[i], strlen(a[i]));
        printf("\n");
        for (int j = 0; j < strlen(a[i]); j++)
        {
            if ((a[i][j] >= 0 && a[i][j] <= 9) || a[i][j] = ".")
                printf("数是合法的\n");
        }
    }
    system("pause");
    return 0;
}