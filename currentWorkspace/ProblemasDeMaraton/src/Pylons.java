import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Pylons {
	static int[] memo;
	static int R,C;
	static StringBuilder builder;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		int T=Integer.parseInt(br.readLine());
		for (int t = 0;t < T; t++) {
			String[] A=br.readLine().split("\\s+");
			memo=new int[(1<<25)];
			for (int i = 0; i < memo.length; i++) {
				memo[i]=-1;
			}
			R=Integer.parseInt(A[0]);
			C=Integer.parseInt(A[1]);
			boolean possible=false;
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					boolean[][] galaxy=new boolean[R][C];
					galaxy[i][j]=true;
					StringBuilder sb=new StringBuilder();
					sb.append((i+1)+" "+(j+1)+"\n");
					memo[toNumber(galaxy)]=f(i,j,galaxy,1,sb)?1:0;
					possible=possible|memo[toNumber(galaxy)]==1?true:false;
				}
			}
			if(possible) {
				bw.write("Case #"+(t+1)+": POSSIBLE\n");
				bw.write(builder.toString());;
			}else {
				bw.write("Case #"+(t+1)+": IMPOSSIBLE\n");
			}
		}
		bw.close();
		br.close();
	}
	private static int toNumber(boolean[][] galaxy) {
		int num=0;
		for (int i = 0; i < galaxy.length; i++) {
			for (int j = 0; j < galaxy[0].length; j++) {
				if(galaxy[i][j]) {
					num+=(1<<j+galaxy[0].length*i);
				}
			}
		}
		return num;
	}
	private static boolean f(int r, int c, boolean[][] galaxy, int total, StringBuilder sb) {
		if(memo[toNumber(galaxy)]!=-1)return memo[toNumber(galaxy)]==1?true:false;
		if(total==R*C) {
			builder=sb;
			return true;
		}
		boolean ans=false;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if(check(r,c,i,j)&&!galaxy[i][j]) {
					boolean[][] g=new boolean[R][C];
					for (int k = 0; k < g.length; k++) {
						g[k]=galaxy[k].clone();
					}
					g[i][j]=true;
					StringBuilder s=new StringBuilder(sb.toString());
					s.append((i+1)+" "+(j+1)+"\n");
					memo[toNumber(g)]=f(i,j,g,total+1,s)?1:0;
					ans=ans|memo[toNumber(g)]==1?true:false;
				}
			}
		}
		memo[toNumber(galaxy)]=ans?1:0;
		return memo[toNumber(galaxy)]==1?true:false;
	}
	private static boolean check(int r, int c, int i, int j) {
		if(r==i || c==j)return false;
		if(r-c==i-j || r+c==i+j)return false;
		return true;
	}

}
