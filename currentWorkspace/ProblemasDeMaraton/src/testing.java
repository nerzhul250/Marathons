
public class testing {

	public static void main(String[] args) {
		double n=10000000;
		double a=0;
		for (double i = 1; i <= n; i++) {
			a+=1/i;
		}
		System.out.println(a/Math.log(n));
	}

}