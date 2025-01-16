package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.*;
import java.io.*;

public class Main {
    //트리 노드 정보 저장 클래스
    static class node{
        int next, length;
        public node(int next, int length){
            this.next = next;
            this.length = length;
        }
    }
    //트리 저장 정보 리스트
    static ArrayList<ArrayList<node>> tree = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        for (int i = 0; i <= N; i++)
            tree.add(new ArrayList<>());
        // 입력되는 트리 정보 저장
        for (int i = 1; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());
            tree.get(a).add(new node(b, l));
            tree.get(b).add(new node(a, l));
        }

        //M개의 노드쌍 거리 구하기
        for (int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            bw.write(bfs(a,b,N) + "\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
    //노드 쌍 거리 구하기 bfs함수
    static int bfs(int start, int end, int n){
        //bfs에 사용할 큐
        Queue<node> queue = new LinkedList<>();
        //방문노드 visited 행열
        boolean[] visited = new boolean[n + 1];
        //시작 노드 방문 확인
        visited[start] = true;
        //시작 노드 queue 저장
        queue.add(new node(start,0));
        while(!queue.isEmpty()){
            node cur = queue.poll();
            //목적지 도착시
            if (cur.next == end)
                return cur.length;
            //현재 노드 연결된 주변 노드 탐색
            for (node next : tree.get(cur.next)){
                if (!visited[next.next]){
                    visited[next.next] = true;
                    queue.add(new node(next.next, cur.length + next.length));
                }
            }
        }
        return -1;
    }

}