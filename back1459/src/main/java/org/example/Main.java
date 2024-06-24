package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long x,y,s,w;

        String[] t = br.readLine().split(" ");

        x = Integer.parseInt(t[0]);
        y = Integer.parseInt(t[1]);
        w = Integer.parseInt(t[2]);
        s = Integer.parseInt(t[3]);
        long ans = 0;

        if (2 * w < s){
            ans = (x + y) * w;
        }
        else if (2 * w > 2 * s){
            if ((x + y) % 2 == 0){
                ans = Math.max(x,y) * s;
            }
            else{
                ans = (Math.max(x,y) - 1)  * s;
                ans += w;
            }
        }
        else {
            if (x == y){
                ans = x * s;
            }
            else {
                ans = Math.min(x * s, y * s);
                ans += Math.abs(x - y) * w;
            }
        }
        System.out.println(ans);
    }
}