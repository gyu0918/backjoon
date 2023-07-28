import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    static int N, M;
    static boolean visited[][];
    static int map[][];
    static int count = 0;
    static int dx[] = {-1,1,0,0};
    static int dy[] = {0,0,-1,1};
    public static void bfs(int x, int y) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{x,y});

        while(!q.isEmpty()) {
            int now[] = q.poll();
            int nx = now[0];
            int ny = now[1];

            for(int i=0;i<4;i++) {
                int nextX = nx + dx[i];
                int nextY = ny + dy[i];

                if(nextX>=0 && nextX<N && nextY>=0 && nextY<M) {
                    if(map[nextX][nextY]==1 && !visited[nextX][nextY]) {
                        q.add(new int[] {nextX, nextY});
                        visited[nextX][nextY]=true;
                        map[nextX][nextY] = map[nx][ny]+1;
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        N = in.nextInt();
        M = in.nextInt();
        map = new int[N][M];
        visited = new boolean[N][M];
        for (int i = 0; i < N; i++){
            String input = in.next();
            for (int j = 1; j < M; j++){
                map[i][j] = input.charAt(j) - '0';
            }
        }
        visited[0][0] = true;
        bfs(0, 0);
        System.out.println(map[N - 1][M - 1]);
        in.close();
    }
}
