#include <stdio.h>
#include <math.h>

int main()
{
    int N, K;
    int i, j, k;
    int result[10000] = {0};

    scanf("%dlf %d", &N, &K);
    i = 0;
    j = 0;
    while (i < sqrt(N))
    {
        if (N % i == 0)
        {  
            result[j] = i;
            j++;
        }
        i++;
    }
    k = 0;
    while (k < j)
    {
        result[j] = N / result[k]; 
        k++;
        j++;      
    }
    if (j < k)
        printf("0");
    else
        printf("%d", result[k]);
    return (0);
}