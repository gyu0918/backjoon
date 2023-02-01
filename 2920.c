#include <stdio.h>

int main()
{
    int A[8] = {0};
    int i, count;

    i = 0;
    while (i < 8)
    {
         scanf("%d", &A[i]);
         i++;
    }
    i = 0;
    count = 0;
    while (i < 7)
    {
        if (A[i] > A[i + 1])
            count++;
        if (A[i] < A[i + 1])
            count--;
        i++;
    }
    if (count == 7)
        printf("descending");
    else if (count == -7)
        printf("ascending");
    else
        printf("mixed");
    return (0);
}