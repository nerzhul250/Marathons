import java.util.Scanner;

class house {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		long m=sc.nextLong();
		for (long n = m+2; n <=10000000; n++) {
			double val=n*(n+1)+m*(m-1);
			val=val/2;
			long root=(long) Math.round(Math.sqrt(val));
			if(root*root==val) {
				System.out.println(m+" "+root+" "+n);
				break;
			}
		}
	}

}
