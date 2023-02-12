#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int x;
    int y;  
} game;

int compare(const void *a, const void *b)
{
    game A = *(game *)a;
    game B = *(game *)b;
    if (A.x > B.x)
        return (1);
    else if (A.x == B.x)
    {
        if (A.y > B.y)
            return (1);
        else
            return (-1);
    }
    return (-1);
}

int main()
{
    int N, i;

    scanf("%d", &N);
    i = 0;
    game arr[N];
    while (i < N)
    {
        scanf("%d %d", &arr[i].x, &arr[i].y);
        i++;
    }
    qsort(arr, N, sizeof(game), compare);
    i = 0;
    while (i < N)
    {
        printf("%d %d\n", arr[i].x, arr[i].y);
        i++;
    }
    return (0);
}