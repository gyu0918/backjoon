import java.util.Scanner;

public class Main {
    static int map[][];
    static boolean visit[];
    static int N, P, V;
    static int count = 0;

    public static int dfs(int i) {
        visit[i] = true;

        for(int j = 1; j <= N; j++) {
            if(map[i][j] == 1 && visit[j] == false) {
                count ++;
                dfs(j);
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        N = in.nextInt();
        P = in.nextInt();
        V = 1;
        map = new int[N+1][N+1];
        visit = new boolean[N+1];

        for(int i = 0; i < P; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            map[a][b] = map[b][a]= 1;
        }
        System.out.println(dfs(V));
        in.close();
    }
}
