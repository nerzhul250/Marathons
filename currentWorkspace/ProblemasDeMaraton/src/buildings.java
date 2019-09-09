import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;

public class buildings {
	public static int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] line=br.readLine().split("\\s+");
		int mi=Integer.parseInt(line[1]);
		BigInteger n=new BigInteger(line[0]);
		BigInteger m=new BigInteger(line[1]);
		BigInteger c=new BigInteger(line[2]);
		BigInteger MOD=new BigInteger("1000000007");
		BigInteger w=c.modPow(n.multiply(n),MOD);
		BigInteger mInverse=m.modInverse(MOD);
		BigInteger res=BigInteger.ZERO;
		for(int i=1;i<=mi;i++) {
			res=res.add(w.modPow(new BigInteger(gcd(i,mi)+""),MOD)).mod(MOD);
		}
		res=res.multiply(mInverse).mod(MOD);
		bw.write(res+"\n");
		bw.close();
	}

}
