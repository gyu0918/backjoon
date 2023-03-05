#include <stdio.h>

int main()
{
    int         N, M, arr;
    int         i;
    long long   count;
    long long   sum[1000001] = {0};
    long long   remain[1001] = {0};

    scanf("%d %d", &N, &M);
    i = 1;
    while (i <= N)
    {
        scanf("%d", &arr);
        sum[i] = (sum[i - 1] + arr) % M;
        remain[sum[i]]++;
        i++;
    }
    count = remain[0];
    i = 0;
    while (i < M)
    {
        count += (remain[i] * (remain[i] - 1)) / 2;
        i++;
    }
    printf("%lld", count);
    return (0);
}