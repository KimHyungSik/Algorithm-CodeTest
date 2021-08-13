import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BinarySearch4 {

    static FastReader scanner = new FastReader();
    static int N;
    static int[] list;
    static int find, sol = 0;
    static void input(){
        N = scanner.nextInt();

        list = new int[N + 1];

        for(int i = 1; i <= N; i++) list[i] = scanner.nextInt();

        Arrays.sort(list, 1, N + 1);

        find = scanner.nextInt();
    }

    static int upper_bound(int[] A, int L, int R, int sel){
        int mid;
        int re = R  + 1;

        while(L <= R){
            mid = (L + R) / 2;
            if(A[mid] >= sel){
                re = mid;
                R = mid - 1;
            }else{
                L = mid + 1;
            }
        }
        return re;
    }

    static void res(){
        for(int i = 1; i < N; i++){
            // 찾아야 하는 값 에서 기존 값을 빼고 남은 값 중 가장 가까운 값 찾기
            int result = upper_bound(list, 1, N, find - list[i]);
            // 찾은 값이 자신이 아니며 기존 값과 더했을 때 찾는 값이 나오면 쌍 추가
            if(i + 1 <= result -1 && result -1 <= N && list[i] + list[result - 1] == find){
                sol++;
            }
            if(i + 1 <= result && result<= N && list[i] + list[result] == find){
                sol++;
            }
        }
        System.out.println(sol);
    }

    public static void main(String[] args) {
        input();
        res();
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
