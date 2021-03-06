import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

public class Pylons {
	static int R,C;
	static boolean possible;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		int T=Integer.parseInt(br.readLine());
		for (int t = 0;t < T; t++) {
			String[] A=br.readLine().split("\\s+");
			R=Integer.parseInt(A[0]);
			C=Integer.parseInt(A[1]);
			possible=false;
			boolean[][] galaxy=new boolean[R][C];
			ArrayList<Integer> positions=new ArrayList<Integer>();
			for (int i = 0; i < galaxy.length && !possible; i++) {
				for (int j = 0; j < galaxy[0].length && !possible; j++) {
					int movx=(int) (Math.random()*R);
					int movy=(int) (Math.random()*C);
					galaxy[movx][movy]=true;
					positions.add(movx);positions.add(movy);
					f(movx,movy,galaxy,positions,1);
					if(possible)continue;
					galaxy[movx][movy]=false;
					positions.remove(positions.size()-1);positions.remove(positions.size()-1);
				}
			}
			if(possible) {
				bw.write("Case #"+(t+1)+": POSSIBLE\n");
				for (int i = 0; i < positions.size(); i+=2) {
					bw.write((positions.get(i)+1)+" "+(positions.get(i+1)+1)+"\n");
				}
			}else {
				bw.write("Case #"+(t+1)+": IMPOSSIBLE\n");
			}
		}
		bw.close();
		br.close();
	}
	private static boolean f(int r, int c,boolean[][] galaxy,ArrayList<Integer> positions, int total) {
		if(possible)return true;
		if(total==R*C){possible=true;return true;}
		for (int i = 0; i < galaxy.length; i++) {
			for (int j = 0; j < galaxy[0].length; j++) {
				int movx=(int) (Math.random()*R);
				int movy=(int) (Math.random()*C);
				if(check(r,c,movx,movy) && !galaxy[movx][movy]) {
					galaxy[movx][movy]=true;
					positions.add(movx);positions.add(movy);
					f(movx,movy,galaxy,positions,total+1);
					if(possible)return true;
					galaxy[movx][movy]=false;
					positions.remove(positions.size()-1);positions.remove(positions.size()-1);
				}
			}
		}
		return possible;
	}
	private static boolean check(int r, int c, int i, int j) {
		if(r==i || c==j)return false;
		if(r-c==i-j || r+c==i+j)return false;
		return true;
	}

}
