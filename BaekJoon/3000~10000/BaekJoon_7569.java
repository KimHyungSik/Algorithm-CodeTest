import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static class Address{
        int x;
        int y;
        int h;
        public Address(int x, int y, int h) {
            this.x = x;
            this.y = y;
            this.h = h;
        }
    }

    static FastReader fastReader = new FastReader();
    static int N, M, H, counter = 0; // 세로, 가로, 높이
    static int[][][] boxes;
    static Queue<Address> q = new LinkedList<>();
    static void input(){
        M = fastReader.nextInt();
        N = fastReader.nextInt();
        H = fastReader.nextInt();

        boxes = new int [M][N][H];

        for(int i = 0; i < H; i++ ){
            for(int j = 0; j < N; j++){
                for(int k = 0; k < M; k++){
                    boxes[k][j][i] = fastReader.nextInt();
                    counter += boxes[k][j][i] == 0 ? 1 : 0;
                    if(boxes[k][j][i] == 1) q.add(new Address(k,j,i));
                }
            }
        }
    }

    static void dfs(int x, int y, int h, boolean visited[][][]){
        if(visited[x][y][h]) return;
        visited[x][y][h] = true;

        int poc[] = { 1, -1};
        for(int i = 0; i < 2; i++ ){
            tomato(x + poc[i], y, h);
            tomato(x, y + poc[i], h);
            tomato(x, y, h + poc[i]);
        }
    }

    static void tomato(int x, int y,int h){
        if(x < 0 || x >= M || y < 0 || y >= N || h < 0 || h >= H) return;
        if(boxes[x][y][h] == 0) {
            counter--;
            boxes[x][y][h] = 1;
            q.add(new Address(x,y,h));
        }
    }

    public static void main(String[] args) {
        input();
        int result = -1;

        boolean[][][] visited =  new boolean[M][N][H];
        while(!q.isEmpty()) {

            Queue<Address> tq = new LinkedList<>(q);
            q.clear();
            for( Address address : tq)
                dfs(address.x, address.y, address.h, visited);
            result++;
        }
        System.out.println(counter > 0 ? -1 : result);
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastReader(String s) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(new File(s)));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
