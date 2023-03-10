#include <stdio.h>

typedef struct conserting 
{
    int period;
    int pay;
}conserting;

int result;

void    dfs(conserting *conserting, int N, int i, int sum)
{
    if (sum > result)
        result = sum;
    while (i < N)
    {
        if (conserting[i].period + i <= N)
            dfs(conserting, N, i + conserting[i].period, sum + conserting[i].pay);
        i++;
    }
}


int main()
{
    int N, i, j;
    conserting  conserting[15];
    
    result = -1;
    scanf("%d", &N);
    i = 0;
    while (i < N)
    {
        scanf("%d %d", &conserting[i].period, &conserting[i].pay);
        i++;
    }
    i = 0;
    j = 0;
    result = 0;
    dfs(conserting, N, i, 0);
    printf("%d\n", result);
    return (0);
}