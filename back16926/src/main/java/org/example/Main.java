package org.example;

import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       StringTokenizer st = new StringTokenizer(br.readLine());
       int N = Integer.parseInt(st.nextToken());
       int M = Integer.parseInt(st.nextToken());
       int R = Integer.parseInt(st.nextToken());

       int[][] map = new int[N][M];

       //맵만들기
       for (int i = 0; i < N; i++){
           st = new StringTokenizer(br.readLine());
           for (int j = 0; j < M; j++){
               map[i][j] = Integer.parseInt(st.nextToken());
           }
       }
//        (0,0) (0,1) (0,2) (0,3) (0,4)
//        (1,0) (1,1) (1,2) (1,3) (1,4)
//        (2,0) (2,1) (2,2) (2,3) (2,4)
//        (3,0) (3,1) (3,2) (3,3) (3,4)

       //회전회오리 만들기
        int count = Math.min(N,M)/2; //돌아가는 부분이 몇부분으로 나누어 지는지 체크

        for (int i = 0; i < R;i++){  //회전수만큼 돌아야 되니까
            for (int j = 0; j < count; j++){
                int temp = map[j][j];
                //h = N  // w = M
                for (int k = j + 1; k < M - j; k++){ //맨위에 줄
                    map[j][k - 1] = map[j][k];
                }
                for (int k = j + 1; k < N - j; k++){
                    map[k - 1][M - 1 - j] = map[k][M - 1 -j];
                }
                for (int k = M - 2 - j; k >= j; k--){
                    map[N -1 -j][k + 1] = map[N -1 -j][k];
                }
                for (int k = N -2 -j; k >= j; k--){
                    map[k + 1][j] = map[k][j];
                }
                map[j + 1][j] = temp;

            }
        }

        //출력
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++){
            sb = new StringBuilder(M);
            for (int j = 0; j < M; j++){
                sb.append(map[i][j]).append(" ");
            }
            System.out.println(sb);
        }
    }
}