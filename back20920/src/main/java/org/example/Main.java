package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.*;
import java.io.*;

//1. 자주 나오는 단어 일수록 앞에 배치
//2. 해당 단어의 길이가 길수록 앞에
//3. 알파벳 단어 순으로 앞에 배
public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        String[] str = new String[N];
        int[] sameCheck = new int[N];

        //M길이 이상 애들만 배열에 넣음
        for (int i = 0; i < N; i++){
            String temp = br.readLine();
            if (temp.length() >= M) {
                int j = 0;
                for (; j < i; j++){
                    if (str[j].equals(temp)){
                        sameCheck[j]++;
                        break ;
                    }

                }
                str[j] = temp;

            }
        }

        //자주 나오는 순서로 배치 할건데 자주나오는 횟수가 같다면 해당단어길이로 체크하고 3번째는 알파벳 단어순으로체크
        


    }
}