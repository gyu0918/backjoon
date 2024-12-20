package org.example;

import java.util.*;
import java.io.*;

// q= 0.25 d= 0.10 n= 0.05 p= 0.01
// q= 25 d = 10  n = 5 p = 1
//1 <= c <= 500

public class Main {
    static int q = 25, d = 10, n = 5, p = 1;
    static int qq,dd,nn,pp;
    static int c;

    public static void main(String[] args) throws IOException {
        BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(rd.readLine());
        for (int i = 0; i < T; i++){
            qq = 0;
            int c = Integer.parseInt(rd.readLine());
            for (int j = 1; c < q * j; j++){
                if (c == q * j) {
                    qq = j;
                    break;
                }
            }

        }
    }
}