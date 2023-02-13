#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    if (strlen((const char*)a) > strlen((const char *)b))
        return (1);
    else if (strlen((const char*)a) < strlen((const char*)b))
        return (-1);
    else
        return (strcmp((char *)a, (char *)b));
}

int main()
{
    int     N, i;
    char    word[20000][51] = {0};

    scanf("%d", &N);
    i = 0;
    while (i < N)
    {
        scanf("%s", word[i]);
        i++;
    }
    qsort(word, N, sizeof(word[0]), compare);
    i = 0;
    while (i < N)
    {
        if (strcmp(word[i], word[i+1]) != 0 || i == N -1)
        {
            printf("%s\n", word[i]);
        }
        i++;
    }
    return (0);
}