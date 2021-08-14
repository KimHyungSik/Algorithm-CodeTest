import java.io.*;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static FastReader scanner = new FastReader();
    static int N, C; // 집의 개수, 공유기 갯수
    static int result = 0;
    static int[] home; // 집들의 좌표

    static void input(){
        N = scanner.nextInt();
        C = scanner.nextInt();

        home = new int[N + 1];

        for(int i = 1; i <= N; i++) {
            home[i] = scanner.nextInt();
        }

        Arrays.sort(home, 1, N+1);
    }

    static boolean checked(int distance){
        int cnt = 1, last = home[1];

        for(int i = 2; i <= N; i++){
            if(home[i] - last >= distance){
                cnt++;
                last = home[i];
            }
        }

        return cnt >= C;
    }

    static void binarySearch(){
        int L = 1, R = 1000000000;
        int mid;

        while(L <= R){
            mid = (L + R) / 2;
            if(checked(mid)){
                result = mid;
                L = mid + 1;
            }else{
                R = mid -1;
            }
        }
    }

    public static void main(String[] args) {
        input();
        binarySearch();
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
