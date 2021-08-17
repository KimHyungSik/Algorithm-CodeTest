import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

public class TowPointer {

    static FastReader scanner = new FastReader();

    static HashMap<Integer, Boolean> hashMap = new HashMap<>();
    static int N;
    static long result = 1;
    static int[] list;

    static void input(){
        N = scanner.nextInt();

        list = new int[N + 1];

        for(int i = 1; i <= N; i++) {
            list[i] = scanner.nextInt();
            hashMap.put(list[i], false);
        }
    }

    static void pro(){
        int L = 1, R = 1;
        hashMap.put(list[L], true);
        while (R <= N) {
            if(L == R){
                R++;
                continue;
            }
           if(hashMap.get(list[R])){
               hashMap.put(list[L], false);
               result += R - L++;
               hashMap.put(list[L], true);
           }else{
               hashMap.put(list[R++], true);
           }
        }

        while(L < N){
            result += R - L++;
        }
    }

    public static void main(String[] args) {
        input();
        pro();
        System.out.println(result);
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
