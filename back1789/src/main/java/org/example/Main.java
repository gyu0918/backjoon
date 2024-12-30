package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        long S,N,sum;
        S = Long.parseLong(br.readLine());
        N = 0;
        sum = 0;
        for(int i = 1; ;i++){
            if (sum > S){
                break ;
            }
            sum += i;
            N++;
        }
        System.out.println(N - 1);
    }
}