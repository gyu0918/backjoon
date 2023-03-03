#include <stdio.h>

int main()
{
    int N, K, i, j, m, ans;
    int arr[100001] = {0};
    int sum[100001] = {0};
    int result[100001] = {0};

    scanf("%d %d", &N, &K);
    i = 1;
    while (i <= N)
    {
        scanf("%d", &arr[i]);
        sum[i] = sum[i - 1] + arr[i];
        i++;
    }
    i = 1;
    while (i <= N - K + 1)
    {
        result[i] = sum[i + K - 1] - sum[i - 1];
        if (i == 1)
            ans = result[i];
        else if (result[i] > result[i - 1])
            ans = result[i];
        else if (result[i] < result[i - 1])
            ans = result[i - 1];
        i++;
    }
    printf("%d\n", ans);
    return (0);
}