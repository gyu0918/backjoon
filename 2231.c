#include <stdio.h>

int main()
{
    int i, n;
    scanf("%d", &n);
    int sum;
    i = 1;
    while (i <= n)
    {
        int a = i;
        sum = i; // 초기화
        while(a > 0) // 각 자리수 뽑고 sum에 저장하면서 진행
        {
            sum = sum + a % 10;
            a = a / 10;
        }
        if (sum == n) // n값이 되었다. i출력
        {
            printf("%d", i);
            break;
        }
        if (i == n) // n값을 못찾았다. (배열을 끝까지 돌렸다.)
        {
            printf("0");
            break;
        }
        i++;
    }
}
