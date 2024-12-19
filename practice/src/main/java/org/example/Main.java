package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.awt.print.Pageable;
import java.util.*;
import java.io.*;

public class Main {
//    public static void main(String[] args) throws IOException{
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        StringTokenizer st = new StringTokenizer(br.readLine());
//        int N = Integer.parseInt(st.nextToken());
//        int M = Integer.parseInt(st.nextToken());
//        System.out.println("N= " + N + " " + "M= " + M);
//
//        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//        String s = "fuck OverWatch";
//        bw.write(s);
//        bw.newLine();
//        bw.flush();
//        bw.close();
//    }
//    public static void main(String [] args) throws IOException{
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        StringTokenizer st = new StringTokenizer(br.readLine());
//
//        String i = st.nextToken();
//        int s = Integer.parseInt(st.nextToken());
//        System.out.println(i);
//        System.out.println(s);
//    }
    public static void main(String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try{
            System.out.println("Enter a String ");
            String s = br.readLine();
            if (s != null && !s.isEmpty()){
                System.out.println("first chacter is = " + s.charAt(0));
            }else {
                System.out.println("No input provided or input is empty ");
            }
        }catch (IOException e){
            System.out.println("error " + e.getMessage());
        }
    }
}