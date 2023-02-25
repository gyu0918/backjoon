#include <stdio.h>
#include <stdlib.h>

int Search(int *original, int left, int right, int count, int target)
{
    int i, mid, result;

    mid = (left + right) / 2;
    if (left > right)
        return (count);
    else
    {
        if (original[mid] > target)
        {
            result = Search(original, left, mid -1, count, target);
        }    
        else if (original[mid] < target)
        {
            result = Search(original, mid + 1, right, count, target);
        }
        else
        {
            result = Search(original, left, mid - 1, count, target);
            result += Search(original, mid + 1, right, count, target);
            result += 1;
        }
        return (result);
    }
}

int compare(const void *first, const void *second)
{
    if (*(int *)first > *(int *)second)
        return (1);
    else if (*(int *)first < *(int *)second)
        return (-1);
    else
        return (0);
}

int main()
{
    int N, M, i;
    int original[500001] = {0};
    int com[500001] = {0};
    int count, left, right;

    scanf("%d", &N);
    i = 0;
    while (i < N)
    {
        scanf("%d", &original[i]);
        i++;
    }
    scanf("%d", &M);
    qsort(original, N, sizeof(int), compare);
    i = 0;
    while (i < M)
    {
        scanf("%d", &com[i]);
        left = 0;
        right = N - 1;
        count = 0;
        printf("%d ", Search(original, left, right, 0, com[i]));
        i++;
    }
    return (0);
}