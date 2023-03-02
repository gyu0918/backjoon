#include <stdio.h>
int arr[100001];
long long sum[100001];
 
int main(void) {
    int N, M, i, j;
    long long ans;
    scanf("%d %d", &N, &M);
 
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        sum[i] = sum[i - 1] + arr[i];
    }
 
    while (M--) {
        scanf("%d %d", &i, &j);
        ans = sum[j] - sum[i - 1];
        printf("%lld\n", ans);
    }
 
    return 0;
}