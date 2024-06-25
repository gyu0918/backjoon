package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Integer[] A = new Integer[N];
        Integer[] B = new Integer[N];
        int sum;

        StringTokenizer stA = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++){
            A[i] = Integer.parseInt(stA.nextToken());
        }

        StringTokenizer stB = new StringTokenizer(br.readLine());
        for (int j = 0; j < N; j++){
            B[j] = Integer.parseInt(stB.nextToken());
        }

        Arrays.sort(A);
        Arrays.sort(B, Collections.reverseOrder());
        sum = 0;
        for (int k = 0; k < N; k++){
            sum += A[k] * B[k];
        }
        System.out.println(sum);
    }
}