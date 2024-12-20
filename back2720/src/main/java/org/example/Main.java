package org.example;

import java.util.*;
import java.io.*;

// q= 0.25 d= 0.10 n= 0.05 p= 0.01
// q= 25 d = 10  n = 5 p = 1
//1 <= c <= 500

public class Main {
    static int q = 25, d = 10, n = 5, p = 1;
    static int countq, countd, countn, countp;
    static int c;

    public static void main(String[] args) throws IOException {
        BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(rd.readLine());
        for (int i = 0; i < T; i++){
            int c = Integer.parseInt(rd.readLine());

            if (c < 1 || c > 500) { // 입력값 범위 검증
                throw new IllegalArgumentException("c must be between 1 and 500");
            }

            countq = c /q;
            c = c % q;
            countd = c / d;
            c = c % d;
            countn = c / n;
            c = c % n;
            countp = c / p;
            c = c % p;
            System.out.println(countq + " " + countd + " " + countn + " " + countp);
        }
    }
}