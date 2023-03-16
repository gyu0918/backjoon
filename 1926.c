#include <stdio.h>
#define MAX 500

int picture[MAX][MAX];
int visited[MAX][MAX];
int components;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int answer[MAX];

int floodfill(int x, int y)
{
    int i;
    int newX, newY;
    
    visited[x][y] = 1;
    components++;
    i = 0;
    while (i < 4)
    {
        newX = x + dx[i];
        newY = y + dy[i];
        if (0 <= newX && newX < MAX && 0 <= newY && newY < MAX)
        {
            if (visited[newX][newY] == 0 && picture[newX][newY] == 1)
            {
                floodfill(newX, newY);
            }
        }
        i++;
    }
    return components;
}

int main()
{
    int n,m,i,j,count = 0;
    int max = 0;

    scanf("%d %d", &n, &m);
    i = 0;
    while (i < n)
    {
        j = 0;
        while (j < m)
        {
            scanf("%d", &picture[i][j]);
            j++;
        }
        i++;
    }
    i = 0;
    while (i < n)
    {
        j = 0;
        while (j < m)
        {
            if (visited[i][j] == 0 && picture[i][j] == 1)
            {
                components = 0;
                answer[count] = floodfill(i, j);
                count++;
            }
            j++;
        }
        i++;
    }
    printf("%d\n", count);
    i = 0;
    while (i < count)
    {
        if (max < answer[i])
        {
            max = answer[i];
        }
        i++;    
    }
    printf("%d", max);
    return 0;
}