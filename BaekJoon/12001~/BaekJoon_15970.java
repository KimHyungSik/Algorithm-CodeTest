import java.util.ArrayList;
import java.util.Collections;
import java.util.Objects;
import java.util.Scanner;

public class Main {

    static ArrayList<Point> points = new ArrayList<>();
    static int N, distance = 0;

    public static class Point implements Comparable<Point>{
        int point, color, dis;

        public Point(int point, int color) {
            this.point = point;
            this.color = color;
            this.dis = Integer.MAX_VALUE;
        }

        @Override
        public int compareTo(Point o) {
            if(this.color == o.color) return this.point - o.point;
            return this.color - o.color;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Point point1 = (Point) o;
            return color == point1.color;
        }

        @Override
        public String toString() {
            return "Point{" +
                    "point=" + point +
                    ", color=" + color +
                    ", dis=" + dis +
                    "}\n";
        }
    }

    public static void input(){
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();

        for(int i = 0; i < N; i++){
            int point, color;
            point = scanner.nextInt();
            color = scanner.nextInt();
            points.add(new Point(point, color));
        }

    }

    public static void renewalDistance(int x, int y){
        if(y < 0 || y >= N) return;
        if(!points.get(x).equals(points.get(y))) return;
        Point px = points.get(x);
        Point py = points.get(y);

        px.dis = Math.min(px.dis, Math.abs(px.point - py.point));
    }

    public static void result(){
        Collections.sort(points);

        for(int i = 0; i < N; i++){
            renewalDistance(i, i + 1);
            renewalDistance(i, i - 1);
        }

        for(Point p : points) distance += p.dis;
    }

    public static void main(String[] args) {
        input();
        result();

        System.out.println(distance);
    }
}

