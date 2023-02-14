#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    if (*(int*)a > *(int*)b)
        return (1);
    else if (*(int*)a < *(int*)b)
        return (-1);
    else
        return (0);
}

int main()
{
    int N, i, result, j;
    int time[1001] = {0};

    scanf("%d", &N);
    i = 0;
    while (i < N)
    {
        scanf("%d", &time[i]);
        i++;
    }
    qsort(time, N, sizeof(int), compare);
    result = 0;
    i = 0;
    while (i < N)
    {
        result += time[i];
        j = 0;
        while (j < i)
        {
            result += time[j];
            j++;
        }
        i++;
    }
    printf("%d", result);
    return (0);
}

