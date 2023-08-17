import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Back2667 {
    static int N;
    static int arr[][];
    static boolean visit[][];
    static int dirX[] = {0,0,-1,1};
    static int dirY[] = {-1,1,0,0};
    static int count = 0;
    static int num = 0;
    static int curX, curY;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        List<Integer> list = new ArrayList<>();

        N = Integer.parseInt(br.readLine());
        arr = new int[N][N];
        visit = new boolean[N][N];

        for(int i = 0; i < N; i++){
            String str = br.readLine();
            for(int j = 0; j < N; j++){
                arr[i][j] = Character.getNumericValue(str.charAt(j));
            }
        }

        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
               if (visit[i][j] == false && arr[i][j] == 1){
                   count = 0;
                   num++;
                   DFS(i, j);
                   list.add(count);
               }
            }
        }

        Collections.sort(list);
        bw.append(num + "\n");
        for(int num : list) {
            bw.append(num + "\n");
        }

        bw.flush();
        bw.close();
    }

    static void DFS(int x, int y){
        visit[x][y] = true;
        arr[x][y] = num;
        count++;

        for (int i = 0; i < 4; i++){
            curX = dirX[i] + x;
            curY = dirY[i] + y;

            if (RangeCheck() && visit[curX][curY] == false && arr[curX][curY] == 1){
                visit[curX][curY] = true;
                arr[curX][curY] = num;
                DFS(curX, curY);
            }
        }
    }

    static boolean RangeCheck() {
        return (curX >= 0 && curX < N && curY >= 0 && curY < N);
    }
}
