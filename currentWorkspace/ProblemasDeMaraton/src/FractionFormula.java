import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
 
public class FractionFormula {
	
	static String ex;
	static int i;
	static long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }
	public static String parse() {
		if(ex.charAt(i)=='(') {
			i++;
			String a=parse();
			i++;
			if(i<ex.length() && ex.charAt(i)=='-') {
				i++;
				String b=parse();
				return subFractions(a,b);
			}else if( i<ex.length() &&  ex.charAt(i)=='+') {
				i++;
				String b=parse();
				return sumFractions(a,b);
			}else {
				return a;
			}
		}else {
			String a=parseFrac();
			if(i<ex.length() && ex.charAt(i)=='-') {
				i++;
				String b=parse();
				return subFractions(a,b)+"";
			}else if(i<ex.length() && ex.charAt(i)=='+') {
				i++;
				String b=parse();
				return sumFractions(a,b)+"";
			}else {
				return a;
			}
		}
	}
	private static String parseFrac() {
		StringBuilder sb=new StringBuilder();
		while(i<ex.length() && ((ex.charAt(i)>='0' && ex.charAt(i)<='9') || ex.charAt(i)=='/')) {
			sb.append(ex.charAt(i));
			i++;
		}
		return sb.toString();
	}
	public static String sumFractions(String f1,String f2) {
		String[] A=f1.split("/");
		String[] B=f2.split("/");
		long a1=Integer.parseInt(A[0]);
		long a2=Integer.parseInt(A[1]);
		long b1=Integer.parseInt(B[0]);
		long b2=Integer.parseInt(B[1]);
		long a=a1*b2+a2*b1;
		long b=a2*b2;
		long d=Math.abs(gcd(a,b));
		return a/d +"/"+ b/d;
	}
	public static String subFractions(String f1,String f2) {
		String[] A=f1.split("/");
		String[] B=f2.split("/");
		long  a1=Integer.parseInt(A[0]);
		long  a2=Integer.parseInt(A[1]);
		long  b1=Integer.parseInt(B[0]);
		long  b2=Integer.parseInt(B[1]);
		long  a=a1*b2-a2*b1;
		long  b=a2*b2;
		long  d=Math.abs(gcd(a,b));
		return a/d +"/"+ b/d;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		ex=br.readLine();
		while(ex!=null && !ex.isEmpty()) {
			i=0;
			bw.write(parse()+"\n");	
			ex=br.readLine();
		}
		bw.close();
	}
 
}