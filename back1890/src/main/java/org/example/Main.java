package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws IOException{
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       int N = Integer.parseInt(br.readLine());
       int[][] board = new int[N][N];
       long[][] dp = new long[N][N];
       //입력
       for (int i = 0; i < N; i++){
           StringTokenizer st = new StringTokenizer(br.readLine());
           for(int j = 0; j < N; j++){
               board[i][j] = Integer.parseInt(st.nextToken());
           }
       }

       dp[0][0] = 1;
       for (int i = 0; i < N; i++){
           for (int j = 0; j < N; j++){
               int next = board[i][j];
               if (next == 0){
                   break ;
               }
               // i + next 가 N 보다 작거나 같으면 아래로 움직인 위치에
               // 현재 위치의 dp 값을 더한다.
               if (i + next < N) {
                   dp[i + next][j] += dp[i][j];
               }

               // j + next 가 N 보다 작거나 같으면 오른쪽으로로 움직인 위치에
               // 현재 위치의 dp 값을 더한다.
               if (j + next < N) {
                   dp[i][j + next] += dp[i][j];
               }
           }
       }

       System.out.println(dp[N - 1][N - 1]);

    }
}