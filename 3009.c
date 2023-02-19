#include <stdio.h>

int main(void)
{
    int x[4], y[4], i;
    
    for(i = 0; i < 3; i++) scanf("%d %d", &x[i], &y[i]);
    /*x값 서로 비교하여 겹치지 않은 x값을 x[3]에 대입*/
    if(x[0] == x[1]) x[3] = x[2];
    else if(x[0] == x[2]) x[3] = x[1];
    else x[3] = x[0];
    
    /*y값 서로 비교하여 겹치지 않은 y값을 y[3]에 대입*/
    if(y[0] == y[1]) y[3] = y[2];
    else if(y[0] == y[2]) y[3] = y[1];
    else y[3] = y[0];
    
    printf("%d %d\n", x[3], y[3]);
    return 0;
}