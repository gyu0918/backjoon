#include <stdio.h>

int main()
{
    int N;
    char arr[1000] = {0};

    scanf("%s", arr);
    scanf("%d", &N);
    printf("%c", arr[N - 1]);
    return (0);
}