
import java.util.Scanner;

public class santa {

	public static void main(String[] args) {
		String[] ans={"1.00000000","0.50000000","0.66666667","0.62500000","0.63333333","0.63194444","0.63214286","0.63211806","0.63212081","0.63212054","0.63212056","0.63212056"};
		Scanner sc=new Scanner(System.in);
		long n=sc.nextLong();
		if(n<=11){
			System.out.println(ans[(int) (n-1)]);
		}else{
			System.out.println(ans[11]);
		}
	}

}
