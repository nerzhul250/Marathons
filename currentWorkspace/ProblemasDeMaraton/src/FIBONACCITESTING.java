import java.math.BigInteger;

public class FIBONACCITESTING {
	static BigInteger[] buff;
	public static void main(String[] args) {
		for (int i = 1; i <=60; i++) {
			int found=0;
			int counter=0;
			int firstIndex=0;
			buff=new BigInteger[2];
			buff[0]=BigInteger.ONE;
			buff[1]=BigInteger.ONE;
			for (int j = 0; j < 1000 && found!=2; j++) {
				if(found!=0)counter++;
				BigInteger val=buff[0].add(buff[1]);
				buff[0]=buff[1];
				buff[1]=val;
				if(val.mod(new BigInteger(i+"")).equals(BigInteger.ZERO)) {
					found++;
					if(found==1)firstIndex=j;
				}
			}
			System.out.println(firstIndex+",");
		}
	}

}
