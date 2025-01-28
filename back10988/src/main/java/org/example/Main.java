package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int checkPlag = 1;
        for (int i = 0; i < (str.length()/2) ;i++){
            if (str.charAt(i) != str.charAt(str.length() -1 - i))
                checkPlag = 0;
        }
        System.out.println(checkPlag);
    }
}