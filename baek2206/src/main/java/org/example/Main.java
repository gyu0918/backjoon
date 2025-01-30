//package org.example;
//
//// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
//// then press Enter. You can now see whitespace characters in your code.
//import java.util.*;
//import java.io.*;
//
//
//public class Main {
//    static int N, M, count, ans;
//    static int[] dx = {0,0,1,-1};
//    static int[] dy = {1,-1,0,0};
//    static int[][] map;
//    static boolean[][] visited;
//
//    public static void main(String[] args) throws IOException{
//       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//       StringTokenizer st = new StringTokenizer(br.readLine());
//       N = Integer.parseInt(st.nextToken());
//       M = Integer.parseInt(st.nextToken());
//       map = new int[N][M];
//       count = 1;
//       visited = new boolean[N][M];
//
//       //입력받기
//       for (int i = 0; i < N; i++){
//           String temp = br.readLine();
//           for (int j = 0; j < M; j++){
//                map[i][j] = temp.charAt(j) - '0';
//           }
//       }
//
//       //bfs활용해서
//        visited[0][0] = true;
//        ans = -1;
//        bfs();
//        System.out.println(ans);
//
//    }
//    static void bfs(){
//        Queue<temp> q = new LinkedList<>();
//        q.add(new temp(0,0,1, false));
//        while (!q.isEmpty()){
//            temp temp = q.poll();
//            if (temp.x == N - 1 && temp.y == M - 1){
//                ans = temp.count;
//                break;
//            }
//            for (int i = 0; i < 4; i++){
//                int nx = dx[i] + temp.x;
//                int ny = dy[i] + temp.y;
//                //범위 밖에 나가는 조건
//                if (nx < 0 || ny < 0 || nx >= N || ny >= M){
//                    continue;
//                }
//                //벽이 없고 간적이 없는 경우
//                if (map[nx][ny] == 0 && !visited[nx][ny]){
//                    q.add(new temp(nx,ny,count + 1,temp.wall));
//                    visited[nx][ny] = true;
//                }
//                //벽이 있고 벽 카운트가 남아 있고 간적이 없는경우
//                if (map[nx][ny] == 1 && !temp.wall){
//                    q.add(new temp(nx,ny,count + 1,true));
//                    visited[nx][ny] = true;
//                }
//
//            }
//
//        }
//    }
//    public static class temp{
//        int x;
//        int y;
//        int count;
//        boolean wall;
//
//        public temp(int x, int y, int count, boolean wall) {
//            this.x = x;
//            this.y = y;
//            this.count = count;
//            this.wall = wall;
//        }
//    }
//
//}
package org.example;
import java.util.*;
import java.io.*;

public class Main {
    static int N, M, ans;
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};
    static int[][] map;
    static boolean[][][] visited; // 3차원 방문 배열 (벽을 부쉈는지 여부)

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[N][M];
        visited = new boolean[N][M][2];

        // 입력받기
        for (int i = 0; i < N; i++) {
            String temp = br.readLine();
            for (int j = 0; j < M; j++) {
                map[i][j] = temp.charAt(j) - '0';
            }
        }

        // BFS 실행
        ans = bfs();
        System.out.println(ans);
    }

    static int bfs() {
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(0, 0, 1, false)); // (0,0)에서 시작, 벽 안 부숨

        visited[0][0][0] = true;

        while (!q.isEmpty()) {
            Node temp = q.poll();

            if (temp.x == N - 1 && temp.y == M - 1) {
                return temp.count; // 도착하면 거리 반환
            }

            for (int i = 0; i < 4; i++) {
                int nx = temp.x + dx[i];
                int ny = temp.y + dy[i];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                // 벽이 없는 경우
                if (map[nx][ny] == 0) {
                    if (!visited[nx][ny][temp.wallUsed ? 1 : 0]) {
                        q.add(new Node(nx, ny, temp.count + 1, temp.wallUsed));
                        visited[nx][ny][temp.wallUsed ? 1 : 0] = true;
                    }
                }

                // 벽이 있는 경우 (벽을 아직 안 부쉈을 때만 가능)
                if (map[nx][ny] == 1 && !temp.wallUsed) {
                    q.add(new Node(nx, ny, temp.count + 1, true));
                    visited[nx][ny][1] = true;
                }
            }
        }
        return -1; // 도달 불가능하면 -1 반환
    }

    public static class Node {
        int x, y, count;
        boolean wallUsed; // 벽을 부쉈는지 여부

        public Node(int x, int y, int count, boolean wallUsed) {
            this.x = x;
            this.y = y;
            this.count = count;
            this.wallUsed = wallUsed;
        }
    }
}
