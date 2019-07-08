

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class PayThePrice {
	static long[][][] dp;
	public static long ways(int n, int i,int L) {
		if(n==0 && L==0)return 1;
		if(n<0 || i>300||L==0)return 0;
		if(dp[n][i][L]!=-1)return dp[n][i][L];
		return dp[n][i][L]=ways(n-i,i,L-1)+ways(n,i+1,L);
	}
	public static void main(String[] args) throws IOException {
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String A=br.readLine();
		dp=new long[301][301][301];
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp.length; j++) {
				for (int j2 = 0; j2 < dp.length; j2++) {
					dp[i][j][j2]=-1;
				}
			}
		}
		while(A!=null && !A.isEmpty()) {
			String[] B=A.split("\\s+");
			if(B.length==1) {
				int n=Integer.parseInt(B[0]);
				long suma=0;
				for(int i=0;i<301;i++) {
					suma+=ways(n,1,i);
				}
				bw.write(suma+"\n");
			}else if(B.length==2) {
				int n=Integer.parseInt(B[0]);
				int L=Integer.parseInt(B[1]);
				long suma=0;
				for (int i = 0; i <= L && i<301; i++) {
					suma+=ways(n,1,i);
				}
				bw.write(suma+"\n");
			}else {
				int n=Integer.parseInt(B[0]);
				int L1=Integer.parseInt(B[1]);
				int L2=Integer.parseInt(B[2]);
				long suma=0;
				for(int i=L1;i<=L2 && i<301;i++) {
					suma+=ways(n,1,i);
				}
				bw.write(suma+"\n");
			}
			A=br.readLine();
		}
		bw.close();
		br.close();
	}

}
