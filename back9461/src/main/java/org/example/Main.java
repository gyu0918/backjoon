package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int N;
        long[] P = new long[101];

        P[1] = P[2] = P[3] = 1;
        P[4] = P[5] = 2;
        for (int j = 6; j < 101; j++){
            P[j] = P[j - 3] + P[j - 2];
        }

        for (int i = 0; i < T; i++){
            N = sc.nextInt();
            System.out.println(P[N]);
        }
    }
}