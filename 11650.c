#include <stdio.h>

int main()
{
    int N, i, j, temp1;
    int temp2;
    int result[][] = {0};

    scanf("%d", &N);
    i = 0;
    while (i < N)
    {
        scanf("%d %d", &result[i][0], &result[i][1]);
        i++;
    }
    j = 0;
    i = 0;
    while (i < N)
    {
        j = i + 1;
        temp1 = 0;
        temp2 = 0;
        while (j < N)
        {
            if (result[i][0] > result[j][0])
            {    
                temp1 = result[i][0];
                result[i][0] = result[j][0];
                result[j][0] = temp1;
                temp2 = result[i][1];
                result[i][1] = result[j][1];
                result[j][1] = temp2;
            }
            j++;
        }
        i++;
    }
    j = 0;
    i = 0;
    while (i < N)
    {
        j = i + 1;
        temp1 = 0;
        temp2 = 0;
        while (j < N)
        {
            if (result[i][1] > result[j][1])
            {    
                temp1 = result[i][0];
                result[i][0] = result[j][0];
                result[j][0] = temp1;
                temp2 = result[i][1];
                result[i][1] = result[j][1];
                result[j][1] = temp2;
            }
            j++;
        }
        i++;
    }
    i = 0;
    while (i < N)
    {
        printf("%d %d", result[i][0], result[i][1]);
        i++;
    }
    return (0);
}