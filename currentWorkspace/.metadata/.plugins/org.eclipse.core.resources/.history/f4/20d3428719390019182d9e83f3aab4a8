import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class HighScore {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		BigInteger a;
		BigInteger b;
		BigInteger c;
		BigInteger d;
		long[] arr=new long[3];
		for (int i = 0; i < n; i++) {
			arr[0]=sc.nextLong();
			arr[1]=sc.nextLong();
			arr[2]=sc.nextLong();
			Arrays.sort(arr);
			a=BigInteger.valueOf(arr[0]);
			b=BigInteger.valueOf(arr[1]);
			c=BigInteger.valueOf(arr[2]);
			d=BigInteger.valueOf(sc.nextLong());
			if((a.compareTo(b)==0 &&b.compareTo(c)==0) || (c.compareTo(b)>0 && b.compareTo(a)==0)) {
				System.out.println(op(a,b,c.add(d)));
			}else{
				if(BigInteger.valueOf(2).multiply(a).add(BigInteger.valueOf(7)).compareTo(BigInteger.valueOf(2).multiply(c))>0) {
					BigInteger dif=b.subtract(a);
					BigInteger sus=d.min(dif);
					a=a.add(sus);
					d=d.subtract(sus);
					if(d.compareTo(BigInteger.ZERO)>0) {
						c=c.add(d);
					}
					System.out.println(op(a,b,c));
				}else {
					System.out.println(op(a,b,c.add(d)));
				}
			}
		}
		
	}
	
	static BigInteger op(BigInteger a,BigInteger b,BigInteger c) {
		return a.multiply(a).add(b.multiply(b)).add(c.multiply(c)).add(BigInteger.valueOf(7).multiply(a.min(b).min(c)));
	}
}
