package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.*;
import java.io.*;


public class Main {
    static int M, N;
    static int[][] map;
    static int[][] dp;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        map = new int[M][N];
        dp = new int[M][N];

        //map 입력받기
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                dp[i][j] = -1; //dp초기화
            }
        }
        System.out.println(dfs(0, 0));
    }

    public static int dfs(int x, int y) {
        //종료조건
        if (x == M - 1 && y == N -1)
            return 1;

        //방문한 적이 없는 경우
        if (dp[x][y] == -1){
            dp[x][y] = 0;
            for (int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx > M - 1 || ny > N - 1)
                    continue;
                //내리막일 경우
                if (map[x][y] > map[nx][ny]){
                    dp[x][y] += dfs(nx,ny);
                }
            }
        }
        return dp[x][y];
    }
}