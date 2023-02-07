#include <stdio.h>
#include <stdlib.h>

int BSearch(int arr[], int target, int N) 
{
    int low = 0;
    int high = N - 1;
    int mid;

    while(low <= high) 
    {
        mid = (low + high) / 2;

        if (arr[mid] == target)
            return 1;
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int compare(const void *first, const void *second)
{
    if (*(int*)first > *(int*)second)
        return (1);
    else if (*(int*)first < *(int*)second)
        return (-1);
    else
        return (0);
}

int main()
{
    int N, M;
    int i;
    int original[100001];
    int result[100001];

    scanf("%d", &N);
    i = 0;
    while (i < N)
    {
        scanf("%d", &original[i]);
        i++;
    }
    qsort(original, N, sizeof(int), compare);
    scanf("%d", &M);
    i = 0;
    while (i < M)
    {
        scanf("%d", &result[i]);
        if (BSearch(original, result[i], N) == 1)
            printf("1\n");
        else
            printf("0\n");
        i++;
    }
    return (0);
}