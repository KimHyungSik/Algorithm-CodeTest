import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Dijkstra2 {

    static class Edge implements Comparable<Edge>{
        public int distance;
        public int vertex;

        Edge(int distance, int vertex){
            this.distance = distance;
            this.vertex = vertex;
        }

        @Override
        public int compareTo(Edge o) {
            return this.distance - o.distance;
        }
    }

    static FastReader fastReader = new FastReader();
    static int N, M, From, To;
    static ArrayList<Edge>[] list;
    static int[] dist;

    static void input(){
        N = fastReader.nextInt();
        M = fastReader.nextInt();

        list = new ArrayList[N + 1];
        dist = new int[N + 1];
        
        for (int i = 1; i <= N; i++) list[i] = new ArrayList<Edge>();
        for (int i = 1; i <= N; i++) dist[i] = Integer.MAX_VALUE;
        for(int i = 0; i < M; i++){
            int from = fastReader.nextInt(), to = fastReader.nextInt(), dis = fastReader.nextInt();
            list[from].add(new Edge(dis, to));
        }

        From = fastReader.nextInt();
        To = fastReader.nextInt();

        dist[From] = 0;
    }

    static void dijkstra(){
        PriorityQueue<Edge> queue = new PriorityQueue<>();

       queue.add(new Edge(0, From));

        while(!queue.isEmpty()){
            Edge edge = queue.poll();
            int currentVertex = edge.vertex;
            int currentDist = edge.distance;

            if(dist[currentVertex] < currentDist) continue;

            for(Edge to : list[currentVertex]){
                if(dist[to.vertex] > currentDist + to.distance){
                    dist[to.vertex] = currentDist + to.distance;
                    queue.add(new Edge(currentDist + to.distance , to.vertex));
                }
            }
        }

    }

    public static void main(String[] args) {
        input();
        dijkstra();

        System.out.println(dist[To]);
    }

    static class FastReader{
        BufferedReader br;
        StringTokenizer st;

        public FastReader(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next(){
            while(st == null || !st.hasMoreElements()){
                try{
                    st = new StringTokenizer(br.readLine());
                }catch(IOException e){
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {return Integer.parseInt(next());}
    }
}
