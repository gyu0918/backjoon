#include <stdio.h>

int main()
{
    int n;
    int i, j;
    int h[51];
    int w[51];
    int count;
    scanf("%d", &n);
    i = 0;
    while (i < n)
    {
        scanf("%d", &h[i]);
        scanf("%d", &w[i]);
        i++;
    }
    i = 0;
    while (i < n)
    {
        j = 0;
        count = 0;
        while (j < n)
        {
            if (h[i] < h[j] && w[i] < w[j])
            {
                count++;
            }
            j++;
        }
        i++;
        printf("%d ", count + 1);
    }
}
