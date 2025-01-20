package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.*;
import java.io.*;

class iceBerg{
    int x;
    int y;
    public iceBerg(int x, int y){
        this.x=x;
        this.y=y;
    }
}

public class Main {

    static int[] dx = {-1,0,1,0};
    static int[] dy = {0,1,0,-1};
    static int N,M;
    static int[][] map;

    static boolean[][] visited;
    public static void main(String[] args) throws IOException {
        // dfs, bfs 를 써야되는 기준을 세워야 되는데 모르네?
        //-> 빙산 주위에 물이 있는지 확일 할려고 bfs를 사용한다
        // 빙산이 덩어리로 구분될수 있는 기준을 생각해보자

        // 입력도구
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N][M];

        //지도 입력
        for (int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for (int  j = 0; j < M; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        //덩어리 부터 체크 몇덩어리 인지 dfs로체크
        int year = 0;
        while (true){
            int result = iceLandCount();
            if (result >= 2){
                break ;
            }else if (result == 0){
                //빙산이 다 녹았는데 덩어리로 나누어지지 않아서
                year = 0;
                break ;
            }
            bfs();
            year++;
        }
        System.out.println(year);
    }
    //빙산 덩어리 개수 세기
    public static int iceLandCount(){
        boolean[][] visited = new boolean[N][M];
        int iceLand = 0;
        for (int  i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (!visited[i][j] && map[i][j] > 0){
                    dfs(i, j, visited);
                    iceLand++;
                }
            }
        }
        return iceLand;
    }
    //dfs이용 빙산 덩어리 개수 세기
    public void  dfs(int x, int y, boolean[][] visited){
        visited[x][y] = true;
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M){
                if (!visited[nx][ny] && map[nx][ny] > 0){
                    dfs(nx,ny,visited);
                }
            }
        }
    }

    //빙산 녹이는 bfs
    public static void bfs(){
        Queue<iceBerg> q = new LinkedList<>();
        boolean[][] visited = new boolean[N][M];

        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (map[i][j] > 0){
                    q.add(new iceBerg(i, j));
                    visited[i][j] = true;
                }
            }
        }
        while (!q.isEmpty()) {
            iceBerg ice = q.poll();

            int sea = 0; // 빙산 상하좌우에 존재하는 바닷물 영역의 개수

            for (int i = 0; i < 4; i++) {
                int nx = ice.x + dx[i];
                int ny = ice.y + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                    if (!visited[nx][ny] && map[nx][ny] == 0) {
                        sea++;
                    }
                }
            }

            if (map[ice.x][ice.y] - sea < 0) {
                map[ice.x][ice.y] = 0; // 각 칸에 저장된 높이는 0보다 더 줄어들지 않기 때문에 0보다 작아지는 경우 0을 저장
            } else {
                map[ice.x][ice.y] -= sea;
            }
        }
    }
}