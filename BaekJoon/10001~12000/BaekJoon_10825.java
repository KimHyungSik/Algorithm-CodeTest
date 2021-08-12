import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Sort {
    static Scanner scanner = new Scanner(System.in);
    static ArrayList<Elem> elems = new ArrayList<>();
    static int length;

    static class Elem implements Comparable<Elem>{

        public String name;
        public int korean, english, math;
        

        public Elem(String name, int korean, int english, int math) {
            this.name = name;
            this.korean = korean;
            this.english = english;
            this.math = math;
        }

        @Override
        public int compareTo(Elem o) {
            if(this.korean != o.korean)
                return o.korean - this.korean;
            if(this.english != o.english)
                return this.english - o.english;
            if(this.math != o.math)
                return o.math - this.math;
            return name.compareTo(o.name);
        }

        @Override
        public String toString() {
            return name +'\n';
        }
    }
    
    public static void input(){
        length = scanner.nextInt();

        for(int i = 0; i < length; i++){
            String name = scanner.next();
            int korean = scanner.nextInt();
            int english = scanner.nextInt();
            int math = scanner.nextInt();

            elems.add(new Elem(name, korean, english, math));
        }
    }

    public static void main(String[] args) {
    
        input();  

        Collections.sort(elems);

        for(Elem name : elems)
            System.out.println(name.name);

        scanner.close();
    }
}
