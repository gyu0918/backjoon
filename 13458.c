#include <stdio.h>

int main()
{
    int N, B, C, i;
    int room[1000001] = {0};
    long long count;

    scanf("%d", &N);
    i = 0;
    while (i < N)
        scanf("%d", &room[i++]);
    scanf("%d %d", &B, &C);
    i = 0;
    count = 0;
    while (i < N)
    {
        if (room[i] - B == 0 || room[i] - B < 0)
            count++;
        else
        {
            room[i] -= B;
            count++;
            if (room[i] / C  == 0)
                count++;
            else
            {
                count += room[i] / C;
                if (room[i] % C != 0)
                    count++;
            }
        }
        i++; 
    }
    printf("%lld\n", count);
    return (0);
}