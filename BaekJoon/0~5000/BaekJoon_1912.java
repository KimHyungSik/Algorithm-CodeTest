package learn;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int i = scanner.nextInt();

		int m[] = new int[i];
		int max;
		int sum[] = new int[i];
		int temp[] = new int[i];

		for (int j = 0; j < i; j++) {
			m[j] = scanner.nextInt();
		}
		max = m[0];
		sum[0] = m[0];
		temp[0] = m[0];

		for (int j = 1; j < i; j++) {
			sum[j] = max(temp[j - 1] + m[j], max(sum[j - 1], m[j]));

			temp[j] = max(temp[j - 1] + m[j], m[j]);
			
			if (max < sum[j])
				max = sum[j];
		}

		System.out.print(max);
		scanner.close();
	}

	static int max(int x, int y) {
		return x > y ? x : y;
	}

}