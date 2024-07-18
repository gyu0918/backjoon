package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int[] arr, dp;

        arr = new int[N + 1];
        dp = new int[K + 1];
        dp[0] = 1;
        for (int  i = 1; i <= N; i++){
            arr[i] = Integer.parseInt(br.readLine());
            for (int j = arr[i]; j <= K; j++){
                dp[j] += dp[j - arr[i]];
            }
        }
        System.out.println(dp[K]);

    }
}