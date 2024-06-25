package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int maxRope;
        Integer[] rope;

        maxRope = 0;
        rope = new Integer[N];
        //rope최대값 저장
        for (int i = 0; i < N; i++){
            rope[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(rope, Collections.reverseOrder());

        for (int i = 0; i < N; i++){
            maxRope = Math.max(maxRope, rope[i] * (i + 1));
        }
        System.out.println(maxRope);
    }
}