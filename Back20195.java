import java.io.*;
import java.util.*;


public class Back20195{
    public static void main(String [] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = Integer.parseInt(br.readLine());

        char [][] cookie = new char[num][num];

        int i;
        int j;
        i = -1;
        while (++i < num){
            String input = br.readLine();
            j = -1;
            while (++j < num)
                cookie[i][j] = input.charAt(j);
        }

        int x = 0, y = 0;

        i = -1;
        while (++i < num){
            boolean flag = false;
            j = -1;
            while (++j < num){
                if (cookie[i][j] == '*'){
                    x = j + 1;
                    y = i + 2;
                    flag = true;
                    break;
                }
            }
            if (flag == true)
                break ;
        }
        int[] size = new int[5];

        i = -1;
        while (++i < x - 1){
            if (cookie[y - 1][i] == '*')
                size[0]++;
        }
        i = x;
        while (i < num){
            if (cookie[y - 1][i] == '*')
                size[1]++;
            i++;
        }
        i = y;
        while (i < num){
            if (cookie[i][x - 1] == '*')
                size[2]++;
            i++;
        }
        i = y;
        while (i < num){
            if (cookie[i][x - 2] == '*')
                size[3]++;
            i++;
        }
        i = y;
        while (i < num){
            if (cookie[i][x] == '*')
                size[4]++;
            i++;
        }

        bw.write(y + " " + x + "\n");
        bw.write(size[0] + " " + size[1] + " " + size[2] + " " + size[3] + " " + size[4]);

        bw.flush();
        bw.close();
        br.close();
    }
}
