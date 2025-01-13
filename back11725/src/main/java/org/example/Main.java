package org.example;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] parent = new int[N + 1];
        // 연결리스트 배열
        ArrayList<Integer>[] adj = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++){
            adj[i] = new ArrayList<>();
        }
        //방문 체크 배열
        boolean[] visited = new boolean[N = 1];
        StringTokenizer st;
        for (int i = 1; i < N; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj[a].add(a);
            adj[b].add(b);
        }
        //BFS를 위한 큐
        Queue<Integer> queue = new LinkedList<>();

        //루트 노드인 1을 큐에 넣고 방문처리
        queue.add(1);
        visited[1] = true;

        //BFS
        while(!queue.isEmpty()){
            int cur = queue.poll();
            // 현재 노드에 연결된 다음 노드들 검색
            for(int next :  adj[cur]){
                //방문했던 노드 라면 건너 뛴다
                if (visited[next]){
                    continue;
                }
                // 다음 노드를 방문 처리하고 큐에 넣는다
                visited[next] = true;
                queue.add(next);
                // 다음 노드의 부모가 현재 노드임 표시
                parent[next] = cur;
            }
        }
        //부모 노드를 출력한다
        for (int i = 2; i < N; i++){
            System.out.println(parent[i]);
        }

    }
}