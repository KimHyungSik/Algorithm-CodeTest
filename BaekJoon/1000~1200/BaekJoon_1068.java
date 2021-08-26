import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Tree2 {

    static FastReader fastReader = new FastReader();
    static int N, delete, result = 0;
    static ArrayList<Integer>[] tree;
    static ArrayList<Integer>[] parent;

    static void input(){
        N = fastReader.nextInt();
        tree = new ArrayList[N];
        parent = new ArrayList[N];

        for(int i = 0; i < N; i++) {
            tree[i] = new ArrayList<>();
            parent[i] = new ArrayList<>();
        }

        for(int i = 0; i < N; i++){
            int n = fastReader.nextInt();
            if(n == -1) continue;
            tree[n].add(i);
        }
        delete = fastReader.nextInt();

        for(ArrayList<Integer> i : tree){
            if(i.contains(delete))
                i.remove(i.indexOf(delete));
        }
    }

    static void dfs(int x, int pre){
        for(int i : tree[x]){
            parent[i].add(pre);
            dfs(i, pre);
        }
    }

    static void pro(){
        for(int i = 0; i < N; i++){
            dfs(i, i);
        }

        for(int i = 0; i < N; i++){
            if(!tree[i].isEmpty()) continue;
            if(parent[i].contains(delete) || i == delete) continue;
            result++;
        }
    }

    public static void main(String[] args) {
        input();
        pro();

//        System.out.println(Arrays.toString(tree));
//        System.out.println(Arrays.toString(parent));
        System.out.println(result);
    }

    static class FastReader{
        BufferedReader br;
        StringTokenizer st;

        FastReader(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next(){
            while(st == null || !st.hasMoreElements()){
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt(){
            return Integer.parseInt(next());
        }
    }
}
