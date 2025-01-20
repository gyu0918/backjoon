package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.*;
import java.io.*;


//0은 이동할 수 있는 곳
//1은 이동할 수 없는 벽
//최단거리? -> BFS
//시작하는 칸과 끝나는 칸도 포함해서 센다.
//벽을 부수는것이 k개까지 가능


//현재 위치, 벽을 부순적이 있는지, 지나간 타일의 수를 저장 클래스
class coordinate{
    int x;
    int y;
    int breakWallCount; //벽을 부순 횟수
    int count; //움직인 거리

    public coordinate(int x, int y, int breakWallCount, int count) {
        this.x = x;
        this.y = y;
        this.breakWallCount = breakWallCount;
        this.count = count;
    }
}
public class Main{

        static int N,M,K;
        static int[][] map;
        static boolean[][][] visited;
        static int[] dx = {0,0,1,-1};
        static int[] dy = {1,-1,0,0};

        public static void main(String[] args) throws IOException{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine());

            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());

            //맵정보 입력
            map = new int[N][M];

            // 벽을 몇 번 부쉈는지에 따라 방문 체크를 따로 해줘야 반례를 해결할 수 있다.
            visited = new boolean[N][M][K + 1];

            //벽 처리 해주기 && 맵그리기   map 에 Integer.parseInt 로 하면 안되나? char에서 인트로 변하는걸로 해야되나
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < M; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
//				if (map[i][j] == 1)
//					visited[i][j] = true;
                }
            }

            //bfs로 최단거리 찾기
            System.out.println(bfs());

        }

        // 막혔을때 처리!
        public static int bfs() {
            Queue<coordinate> q = new LinkedList<>();
            //처음 위치  count 처리!
            q.add(new coordinate(0,0,0,1));

            //처음 0,0 좌표 및 벽관련도 0으로 visited표시!
            visited[0][0][0] = true;

            //맵 탐색
            while (!q.isEmpty()) {
                coordinate cor = q.poll();
                //종료 조건
                if (cor.x == N -1 && cor.y == M -1)
                    return  cor.count;

                for (int i = 0; i < 4; i++) {
                    int nx = cor.x + dx[i];
                    int ny = cor.y + dy[i];

                    //배열을 벗어나는 경우는 제외
                    if (nx < 0 && ny < 0 && nx >= N && ny >= M)
                        continue;

                    //해당 칸이 빈칸이고 방문하지 않는 경우
                    if (map[nx][ny] == 0 && !visited[nx][ny][cor.breakWallCount]) {
                        q.add(new coordinate(nx,ny,cor.count + 1,cor.breakWallCount));
                        visited[nx][ny][cor.count] = true;
                    }


                    //해당 칸이 벽이고, k번 미만으로 벽을 부쉈고, 방문하지 않는 경우
                    if (map[nx][ny] == 1 && cor.breakWallCount < K && !visited[nx][ny][cor.breakWallCount + 1]) {
                        q.add(new coordinate(nx, ny, cor.breakWallCount + 1, cor.count + 1));
                        visited[nx][ny][cor.count + 1] = true;
                    }
                }
            }
            return -1;
        }
    }


