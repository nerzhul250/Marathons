import java.util.Scanner;

public class boss {

	public static void main(String[] args) {
		int n = new Scanner(System.in).nextInt();
		System.out.println(n <= 3 ? "1" : n - 2 + "");
	}
}
