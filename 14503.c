#include <stdio.h>
#include <stdlib.h>
int map[50][50];
int count = 0;
//북(0),동(1),남(2),서(3)
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
// 로봇 청소기가 청소하는 공간 구하기
void robot(int r, int c, int d, int n, int m) {
    int fcond = 1; // while 문을 돌리기 위해 
    int nr, nc;
    while (fcond) {
        // 현재 위치가 0일 때만 청소 후 count
        // 1번 조건
        if(!map[r][c]) {
            count++;
            map[r][c] = 2; // 청소한 공간은 2로 초기화
        }
        // 2번 조건
        for(int i = 0; i < 5; i++) {
            // 2.3, 2.4번 조건
            if ( i == 4 ) {
                // 2.3번 조건
                nr = r - dr[d];
                nc = c - dc[d];
                if (map[nr][nc] != 1 ) {
                    r = nr;
                    c = nc;
                    break;
                } else {
                    // 2.4번 조건
                    fcond = 0; // 청소 끝
                    break;
                }
            }
            // 2.1, 2.2번 조건
            d = (d+3)%4; // 왼쪽 부분에 청소할 공간이 있던 없던 무조건 방향을 바꿔주어서 2.2번 조건까지 충족
            nr = r +dr[d];
            nc = c +dc[d];
            if (map[nr][nc] == 0) {
                r = nr;
                c = nc;
                break;
            }
        }
    }
}
int main()
{
    int n, m, r, c, d;
    //input
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    robot(r, c, d, n, m);
    printf("%d", count);
    return 0;
}

