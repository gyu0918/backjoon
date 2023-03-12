#include <stdio.h>

int main()
{
    int N;
    int count;

    scanf("%d", &N);
    count = N / 4;
    while (count--)
        printf("long ");
    printf("int");
    return (0);
}