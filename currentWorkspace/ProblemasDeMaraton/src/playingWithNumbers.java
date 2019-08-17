import java.math.BigDecimal;

public class playingWithNumbers {

	public static void main(String[] args) {
		float nam=(float)(0.1);
		double nami=(nam);
		double error=nami-((double)0.1);
		BigDecimal error1=new BigDecimal(error);
		System.out.println(error);
		double one=0.1;	
		float sum=(float) 0.0;
		System.out.println(nam);
		System.out.println(sum);
		System.out.println(one);
		for(int i=0;i<10000000;i++) {
			sum+=nam;
			if(i<10) {
				System.out.println(sum+" error1: "+(sum-i*one)+" error2 "+(error1.multiply(new BigDecimal(i+1))));
			}
		}
		System.out.println();
	}

}
