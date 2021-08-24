import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static FastReader fastReader = new FastReader();

    static int R, C, Dx, Dy; // 가로, 세로 , 비버굴 x, y
    static int x, y; // 고슴도치 위치
    static StringBuffer[] map = new StringBuffer[51];
    static int[][] dist = new int[51][51];
    static boolean[][] visit = new boolean[51][51];
    static int[] Xbir = {1, -1, 0, 0};
    static int[] Ybir = {0, 0, 1, -1};
    static Queue<Integer> wa = new LinkedList<>();

    static void input() {
        R = fastReader.nextInt();
        C = fastReader.nextInt();

        for (int i = 0; i < R; i++)
            map[i] = new StringBuffer(fastReader.nextLine());

        for(int i = 0; i <R; i++) for(int j = 0; j < C; j++) {
            if (map[i].charAt(j) == '*') {wa.add(i); wa.add(j);}
            if (map[i].charAt(j) == 'D') {Dx = i; Dy = j;}
            if (map[i].charAt(j) == 'S'){ x = i; y = j;}
            dist[i][j] = 0;
        }
    }

    static void water(){
        Queue<Integer> temp = new LinkedList<>(wa);
        wa.clear();

        while(!temp.isEmpty()){
            int currentX = temp.poll();
            int currentY = temp.poll();
            for (int i = 0; i < 4; i++) {
                int tx = currentX + Xbir[i];
                int ty = currentY + Ybir[i];

                if (tx < 0 || ty < 0 || tx >= R || ty >= C) continue;
                if (map[tx].charAt(ty) == '*' || map[tx].charAt(ty) == 'X' || map[tx].charAt(ty) == 'D') continue;
                map[tx].setCharAt(ty, '*');
                wa.add(tx);
                wa.add(ty);
            }
        }
    }

    static void bfs(){
        Queue<Integer> q = new LinkedList<>();
        q.add(x);
        q.add(y);
        visit[x][y] = true;
        while(!q.isEmpty()){
            water();
            Queue<Integer> tq = new LinkedList<>(q);
            q.clear();
            while(!tq.isEmpty()) {
                int currentX = tq.poll();
                int currentY = tq.poll();
                for (int i = 0; i < 4; i++) {
                    int tx = currentX + Xbir[i];
                    int ty = currentY + Ybir[i];

                    if (tx < 0 || ty < 0 || tx >= R || ty >= C) continue; // 범위 밖이라면 무시
                    if (map[tx].charAt(ty) == '*' || map[tx].charAt(ty) == 'X') continue;   // 물이나 돌 이있어도 무시
                    if (visit[tx][ty]) continue;
                    visit[tx][ty] = true;
                    dist[tx][ty] = dist[currentX][currentY] + 1;
                    q.add(tx);
                    q.add(ty);
                }
            }
        }
    }

    static void pro(){
        bfs();
    }

    public static void main(String[] args) {
        input();
        pro();

        if(dist[Dx][Dy] == 0)
            System.out.println("KAKTUS");
        else
            System.out.println(dist[Dx][Dy]);
    }

    static class FastReader{
        BufferedReader br;
        StringTokenizer st;

        public FastReader(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next(){
            while( st == null || !st.hasMoreElements()){
                try{
                    st = new StringTokenizer(br.readLine());
                }catch (IOException e){
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt(){return  Integer.parseInt(next());}

        String nextLine(){
            String str = "";
            try{
                str = br.readLine();
            }catch (IOException e){
                e.printStackTrace();
            }
            return str;
        }

    }
}

