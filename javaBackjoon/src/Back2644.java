import java.util.Scanner;

//그래프 탐색 문제이다. 그래프 탐색 같은 문제의 경우 그래프 크기가 정말 크지 않다면 BFS가 효율적이다.
//해당 문제는 전체 그래프 탐색이 아니라 특정 지점으로 도달하는 문제이기 때문에 DFS 탐색을 사용했다.
import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static List<Integer>[] relation;
    static boolean[] check;
    static int res = -1;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int i;
        relation = new ArrayList[n + 1];
        check = new boolean[n + 1];
        i = -1;
        while (++i < n + 1){
            relation[i] = new ArrayList<>();
        }

        StringTokenizer st = new StringTokenizer(br.readLine());

        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());

        int l = Integer.parseInt(br.readLine());
        i = -1;
        while (++i < l){
            st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            relation[p].add(c);
            relation[c].add(p);
        }
        dfs(x,y, 0);
        System.out.println(res);
    }

    static void dfs(int start, int end, int cnt) {
        if(start == end) {
            res = cnt;
            return;
        }

        check[start] = true;
        int i;
        i = -1;
        while (++i < relation[start].size()){
            int next = relation[start].get(i);
            if(!check[next]) {
                dfs(next, end, cnt+1);
        }
    }
}
