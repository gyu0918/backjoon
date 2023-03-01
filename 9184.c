#include <stdio.h>

int main()
{
    int i, j, k;
    int arr[21][21][21];
    i = 0;
    while (i <= 20)
    {
        j = 0;
        while (j <= 20)
        {
            k = 0;
            while (k <= 20)
            {
                if (i == 0 || j == 0 || `k == 0)
                {
                    arr[i][j][k] = 1;
                }
                else if (i < j && j < k)
                {
                    arr[i][j][k] = arr[i][j][k - 1] + arr[i][j - 1][k - 1] - arr[i][j - 1][k];
                }
                else
                {
                    arr[i][j][k] = arr[i - 1][j][k] + arr[i - 1][j - 1][k] + arr[i - 1][j][k - 1] - arr[i - 1][j - 1][k - 1];
                }
                k++;
            }
            j++;
        }
        i++;
    }
    while (1)
    {
        scanf("%d %d %d", &i, &j, &k);
        if (i == -1 && j == -1 && k == -1)
            break;
        else if (i <= 0 || j <= 0 || k <= 0)
            printf("w(%d, %d, %d) = 1\n", i, j, k);
        else if (i > 20 || j > 20 || k > 20)
            printf("w(%d, %d, %d) = %d\n", i, j, k, arr[20][20][20]);
        else
            printf("w(%d, %d, %d) = %d\n", i, j, k, arr[i][j][k]);
    }
}