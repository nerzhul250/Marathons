import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;

public class DivideIt {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		int q=Integer.parseInt(br.readLine());
		for (int i = 0; i < q; i++) {
			BigInteger n=new BigInteger(br.readLine());
			BigInteger FIVE=new BigInteger(5+"");
			BigInteger THREE=new BigInteger(3+"");
			BigInteger TWO=new BigInteger(2+"");
			
			int mov3=0;
			while(n.mod(FIVE).equals(BigInteger.ZERO)) {
				n=n.divide(FIVE);
				mov3++;
			}
			int mov2=0;
			while(n.mod(THREE).equals(BigInteger.ZERO)) {
				n=n.divide(THREE);
				mov2++;
			}
			int mov1=0;
			while(n.mod(TWO).equals(BigInteger.ZERO)) {
				n=n.divide(TWO);
				mov1++;
			}
			if(n.equals(BigInteger.ONE)) {
				bw.write((3*mov3+2*mov2+mov1)+"\n");
			}else {
				bw.write("-1\n");
			}
		}
		bw.close();
		br.close();
	}

}
