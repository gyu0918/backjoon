#include <stdio.h>

int main()
{
    int x, y, w, h;
    int A, B;
    int result1, result2, result3, result4;

    scanf("%d %d %d %d", &x, &y, &w, &h);
    A = w - x;
    B = h - y;
    result1 = A;
    result2 = B;
    result3 = x;
    result4 = y;
    while (1)
    {
        if (A == 0)
        {
            printf("%d", result1);
            break ;
        }
        else if (B == 0)
        {
            printf("%d", result2);
            break ;
        }
        else if (x == 0)
        {
            printf("%d", result3);
            break ;
        }
        else if (y == 0)
        {
            printf("%d", result4);
            break ;
        }        
        A--;
        B--;
        x--;
        y--;
    }
    return (0);
}
