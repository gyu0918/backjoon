#include <stdio.h>
#include <stdlib.h>

int compare(const void *first, const void *second)
{
    if (*(int*)first < *(int*)second)
        return (1);
    else if (*(int*)first > *(int*)second)
        return (-1);
    else
        return (0);
}

int main()
{
    int N, j;
    int i;
    int result[11] = {0};

    scanf("%d", &N);
    i = 0;
    while (N > 0)
    {
        result[i] = N%10;
        N = N/10;
        i++;
    }
    j = i;
    qsort(result, j, sizeof(int), compare);
    i = 0;
    while (i < j)
    {
        printf("%d", result[i]);
        i++;
    }
    return (0);
}