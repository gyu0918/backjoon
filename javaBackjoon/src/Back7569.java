import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class tomatto{
    int z;
    int x;
    int y;

    public tomatto(int z, int x, int y) {
        this.z = z;
        this.x = x;
        this.y = y;
    }
}

public class ddd {

    static int M;
    static int N;
    static int H;
    static int[] dx = {-1, 0, 1, 0, 0, 0};  //상하좌우위아래
    static int[] dy = {0, 1, 0, -1, 0, 0};
    static int[] dz = {0, 0, 0, 0, 1, -1};
    static int[][][] box;
    static Queue<tomatto> que;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        M = in.nextInt();
        N = in.nextInt();
        H = in.nextInt();
        box = new int[H][N][M];
        que = new LinkedList<tomatto>();
        for(int i = 0; i < H; i++){
            for(int j = 0; j < N; j++){
                for (int k = 0; k < M; k++){
                    box[i][j][k] = in.nextInt();
                    if (box[i][j][k] == 1)
                        que.add(new tomatto(i,j,k));
                }
            }
        }
        System.out.println(BFS());
    }
    public static int BFS(){
        while (!que.isEmpty()){
            tomatto t = que.remove();
            int z = t.z;
            int x = t.x;
            int y = t.y;
            for (int i = 0; i < 6; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];
                if (nx >= 0 && ny >= 0 && nz >= 0 && nx < N && ny < M && nz < H){
                    if (box[nz][nx][ny] == 0){
                        que.add(new tomatto(nz,nx,ny));
                        box[nz][nx][ny] = box[z][x][y] + 1;
                    }
                }
            }
        }
        int day = Integer.MIN_VALUE;
        for(int i = 0; i < H; i++){
            for (int j = 0; j < N; j++){
                for (int k = 0; k < M; k++){
                    if (box[i][j][k] == 0)
                        return (-1);
                    day = Math.max(day, box[i][j][k]);
                }
            }
        }
        if (day == 1)
            return (0);
        else return day - 1;
    }
}