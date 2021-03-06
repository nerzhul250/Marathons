import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class boxes {

	static int N;
	static long[][] memo;
	static int[] peso;
	static int[] resis;
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		N = Integer.parseInt(br.readLine());
		
		while (N != 0) {
			memo = new long[N+1][3001];
			for (int i = 0; i < memo.length; i++) {
				Arrays.fill(memo[i], -1);
			}
			peso = new int[N];
			resis = new int[N];
			for (int i = 0; i < N; i++) {
				String[] info = br.readLine().split(" ");
				peso[i] = Integer.parseInt(info[0]);
				resis[i] = Integer.parseInt(info[1]);
			}
			long max = 0;
			for (int i = 0; i < N; i++) {
				long act = sol(i, resis[i]);
				max = Math.max(max, act);
			}
			
			
			bw.write(max+"\n");
			

			N = Integer.parseInt(br.readLine());
		}
		bw.flush();
	}

	private static long sol(int index, int disp) {		
		if(memo[index][disp] != -1) return memo[index][disp];
		long max = 0;
		for (int i = index+1; i < N; i++) {
			if(disp >= peso[i])
			{
				max = Math.max(max, sol(i, Math.min(disp-peso[i], resis[i])));
			}
		}
		return memo[index][disp] = 1+max;
	}
}
