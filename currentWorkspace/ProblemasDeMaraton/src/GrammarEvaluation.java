import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;

public class GrammarEvaluation {
	
	static char[] e;
	static int i;
	
	public static BigInteger fact() throws Exception{
	    if(e[i]=='('){
	        i++;
	        BigInteger val1=exp();
	        if(e[i]==')'){
	            i++;
	            return val1;
	        }else{
	        	throw new Exception();
	        }
	    }else{
	    	StringBuilder sb=new StringBuilder();
	        /*if(e[i]>='1' && e[i]<='9'){
	        	sb.append(e[i]);
	            i++;*/
	            while(e[i]>='0' && e[i]<='9'){
	            	sb.append(e[i]);
		            i++;
	            }
	            return new BigInteger(sb.toString());
	        /*}else{
	        	throw new Exception();
	        }*/
	    }
	}

	static BigInteger comp() throws Exception{
	    BigInteger f=fact();
	    if(e[i]=='*'){
	        i++;
	        BigInteger f2=comp();
	        return f.multiply(f2);
	    }else{
	        return f;
	    }
	}
	static BigInteger exp() throws Exception{
		BigInteger val1=comp();
	    if(e[i]=='+'){
	        i++;
	        BigInteger val2=exp();
	        return val1.add(val2);
	    }else{
	        return val1;
	    }
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		int T=Integer.parseInt(br.readLine());
		for (int k = 0; k < T; k++) {
			e=br.readLine().toCharArray();
			StringBuilder sb=new StringBuilder();
	        for(int j=0;j<e.length;j++){
	            if(e[j]!=' '){
	                sb.append(e[j]);
	            }
	        }
	        sb.append("$");
		    e=sb.toString().toCharArray();
		    i=0;
		    try {
		    	BigInteger ans=exp();
		    	if(i!=e.length-1)throw new Exception();
		    	bw.write(ans+"\n");
	        } catch(Exception e) {
		    	bw.write("ERROR\n");
	        }
		}
		bw.close();
		br.close();
	}

}
