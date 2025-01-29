package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.*;
import java.io.*;

public class Main {
    static int INF = 987654321;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(br.readLine());
        int[][] map = new int[N + 1][N + 1];

        //초기값 설정하기 map
        for (int i = 1; i <= N; i++){
            for (int j = 1; j<= N; j++){
                map[i][j] = INF;
                if (i == j)
                    map[i][j] = 0;
            }
        }

        //입력 받을떄 중복나올시 작은 값으로 입력처리
        for (int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            map[a][b] = Math.min(map[a][b],c);
        }

        //플로이드 와샬 알고리즘
        for (int k = 1; k <= N; k++){
            for (int i = 1; i <= N; i++){
                for (int j = 1; j <= N; j++){
                    //최단경로 초기화
                    if (map[i][j] > map[i][k] + map[k][j]){
                        map[i][j] = map[i][k] + map[k][j];
                    }
                }
            }
        }

        //INF 로 되어있는부분 0으로 바꾸고 출력
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                if (map[i][j] == INF)
                    map[i][j] = 0;
                System.out.print(map[i][j] + " ");
            }
            System.out.print("\n");
        }

    }
}