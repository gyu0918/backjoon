#include <stdio.h>
#include <string.h>

int main()
{
    int N, data, order, i;
    int result[10001] = {0}; 
    char command[6] = {0};

    scanf("%d", &N);
    order = 0;
    i = 0;
    while (i < N)
    {
        scanf("%s", command);
        if (!strcmp(command, "push"))
        {
            scanf("%d", &data);
            result[order] = data;
            order++;
        }
        else if (!strcmp(command, "top"))
        {
            if(order == 0)
                printf("-1\n"); 
            else
                printf("%d\n", result[order - 1]);
        }
        else if (!strcmp(command, "size"))
        {
            if (order == 0)
                printf("0\n");
            else
                printf("%d\n", order);
        }
        else if (!strcmp(command, "empty"))
        {
            if (order == 0)
                printf("1\n");
            else
                printf("0\n");
        }
        else if (!strcmp(command, "pop"))
        {
            if (order == 0)
                printf("-1\n");
            else
            {  
                printf("%d\n", result[order - 1]);
                result[order - 1] = 0;
                order--;
            }
        }
        i++;
    }
    return (0);
}