#include <stdio.h>
#include <cstdlib>
#include <string.h>
int main()
{
    char A[1000];
    int Q[1000];
    int B;
    scanf("%s  %d", A, &B);
    if (B <= 0 || B >= 10)
        return false;
    int i = 0, k = 0;
    int m;
    int n = 0;
    int r;
    while (i < strlen(A))
    {
        if (A[i] < '0' || A[i] > '9')
            return false;
        m = A[i] - '0';
        m = m + n;
        if (m >= B)
        {
            Q[k] = m / B;
            n = m % B * 10;
            r = m % B;
            k++;
        }
        else
        {

            n = m * 10;
            if (i != 0||strlen(A) == 1)
            {
                Q[k] = 0;
                k++;
            }
            r = m % B;
        }
            i++;
        
    }
    for (int j = 0; j < k; j++)
        printf("%d", Q[j]);

    printf(" %d", r);
    system("pause");
    return 0;
}