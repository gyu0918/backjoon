#include <stdio.h>

int main()
{
    int         K, N, i, j;
    long long   k_max = 0, max_len = 0, cnt;
    long long   arr[10001] = {0};
    long long   left, mid, right;

    scanf("%d %d", &K, &N);
    i = 0;
    while (i < K)
    {
        scanf("%lld", &arr[i]);
        if (arr[i] > k_max)
            k_max = arr[i];
        i++;
    }
    left = 1;
    right = k_max;
    while (left <= right)
    {
        mid = (left + right) / 2;
        j = 0;
        cnt = 0;
        while (j < K)
        {
            cnt += arr[j] / mid;
            j++;
        }
        if (N <= cnt && max_len < mid)
            max_len = mid;
        if (cnt < N)
            right = mid - 1;
        else
            left = mid + 1;       
    }
    printf("%lld\n", max_len);
    return (0);
}