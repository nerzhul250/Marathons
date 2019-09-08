import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;

public class buildings {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] line=br.readLine().split("\\s+");
		BigInteger n=new BigInteger(line[0]);
		BigInteger m=new BigInteger(line[1]);
		BigInteger c=new BigInteger(line[2]);
		BigInteger MOD=new BigInteger("1000000007");
		BigInteger w=c.modPow(n.multiply(n),MOD);
		BigInteger mInverse=m.modInverse(MOD);
		BigInteger res=w.modPow(m,MOD).subtract(w.mod(MOD)).mod(MOD).multiply(mInverse).mod(MOD).add(w).mod(MOD);
		bw.write(res+"\n");
		bw.close();
	}

}
