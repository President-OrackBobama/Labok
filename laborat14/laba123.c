#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int m[n][n];
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            scanf("%d", &m[i][j]);
        }
    }
    int i = 0, j = 0;
    int counter = 0;
    int lap = 0;
    for (int k = 0; k != n; ++k)
    {
        printf("%d ", m[k][k]);
        i++;
        j++;
        counter++;
    }
    i--;
    j--;

    while (counter != n * n)
    {   
        i--;
        while (i >= 0)
        {
            printf("%d ", m[i][j]);
            i--;
            j--;
            counter++;
        }
        i = n - 1;
        j = n - 1;
        j = (n - 2 - 2 * lap);
        while (j >= 0)
        {
            printf("%d ", m[i][j]);
            i--;
            j--;
            counter++;
        }
        if (counter == n * n)
        {
            break;
        }
        i++;
        j++;
        i++;
        while (i <= n - 1)
        {
            printf("%d ", m[i][j]);
            i++;
            j++;
            counter++;
        }
        if (counter == n * n)
        {
            break;
        }
        i = 0;
        j = 0;
        j = (2 + 2 * lap);
        while (j <= n - 1)
        {
            printf("%d ", m[i][j]);
            i++;
            j++;
            counter++;
        }
        i--;
        j--;
        lap++;
    }
    return 0;
}