import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class manhattanCreepCart {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		int T=Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			String[] A=br.readLine().split("\\s+");
			int P=Integer.parseInt(A[0]);
			int Q=Integer.parseInt(A[1]);
			int[][] manhattan=new int[Q+1][Q+1];
			for (int i = 0; i < P; i++) {
				A=br.readLine().split("\\s+");
				if(A[2].compareTo("S")==0) {
					for (int x = 0; x < manhattan.length; x++) {
						for (int y = Integer.parseInt(A[1])-1; y>=0; y--) {
							manhattan[x][y]++;
						}
					}
				}else if(A[2].compareTo("N")==0) {
					for (int x = 0; x < manhattan.length; x++) {
						for (int y = Integer.parseInt(A[1])+1; y<manhattan.length; y++) {
							manhattan[x][y]++;
						}
					}
				}else if(A[2].compareTo("W")==0) {
					for (int y = 0; y < manhattan.length; y++) {
						for (int x = 0; x < Integer.parseInt(A[0]); x++) {
							manhattan[x][y]++;
						}
					}
				}else if(A[2].compareTo("E")==0) {
					for (int y = 0; y < manhattan.length; y++) {
						for (int x = Integer.parseInt(A[0])+1; x <manhattan.length ; x++) {
							manhattan[x][y]++;
						}
					}
				}
			}
			int max=Integer.MIN_VALUE;
			int xmax=1,ymax=1;
			for (int i = 0; i < manhattan.length; i++) {
				for (int j = 0; j < manhattan.length; j++) {
					if(manhattan[j][i]>max) {
						max=manhattan[j][i];
						xmax=j;
						ymax=i;
					}
				}
			}
			bw.write("Case #"+(t+1)+": "+xmax+" "+ymax+"\n");
		}
		bw.close();
		br.close();
	}

}
