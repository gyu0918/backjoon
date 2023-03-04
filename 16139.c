#include <stdio.h>

int main()
{
    char    str[200001];
    int     i, j, q, first, last;
    char    target;
    int     count;

    scanf("%s", str);
    scanf("%d", &q);
    i = 0;
    count = 0;
    while (i < q)
    {
        scanf("%c %d %d", &target, &first, &last);
        j = first;
        while (j <= last)
        {
            if (str[j] == target)
                count++;
            printf("%d\n", count);
            j++;
        }
        printf("%d", count);
        i++;
    }
    return (0);
}

