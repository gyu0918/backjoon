package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        //hashMap 사용
        Map<String, Integer> map = new HashMap<>();

        //입력 받기
        for (int i = 0; i < N; i++){
            String temp = br.readLine();
            if (temp.length() >= M) {
                map.put(temp, map.getOrDefault(temp, 0) + 1); // 같은 단어일경우 +1 해준다
            }
        }
        //조건대로 비교해서 만들어 보기
        List<String> wordList = map.keySet().stream().collect(Collectors.toList());

        wordList.sort((o1, o2) -> {
            int c1 = map.get(o1);  //빈도수
            int c2 = map.get(o2);  //빈도수

            if (c1 == c2){
                if (o1.length() == o2.length()){
                    return o1.compareTo(o2);
                }
                return  o2.length() - o1.length();
            }
            return c2 - c1;
        });

        //결과 출력
        StringBuilder sb = new StringBuilder();
        for (String word : wordList){
            sb.append(word).append("\n");
        }
        System.out.print(sb);

    }
}