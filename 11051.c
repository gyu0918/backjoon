}
 15         return (result);
 16 }
 17
 18 int     main()
 19 {
 20         int     N, K;
 21         int     result;
 22         int     A, B, C;
 23
 2#include <stdio.h>
#define mod 10007
#define MAX 1001

int dp[MAX][MAX];

void fibo(int n, int k)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i == j || j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            }
        }
    }
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    fibo(n, k);
    printf("%d\n", dp[n][k]);
    return 0;
}
