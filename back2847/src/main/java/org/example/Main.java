package org.example;


import java.io.*;

// 그리디 알고리즘
// 게임을 만든 동준이.
public class Main {
    public static void main(String args[]) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.valueOf(br.readLine());
        int[] levels = new int[n];

        // 레벨에 따른 점수 배열 저장
        for(int i = 0; i < n; i++) {
            int score = Integer.valueOf(br.readLine());
            levels[i] = score;
        }

        if(n == 1) {
            System.out.print(0);
        }
        else {
            int count = 0;

            for(int i = n - 2; i >= 0; i--) {
                int highLevel = levels[i + 1];
                int lowLevel = levels[i];

                if(lowLevel >= highLevel) {
                    count += lowLevel - (highLevel - 1);
                    levels[i] = highLevel - 1;
                }
            }

            System.out.print(count);
        }
    }
}