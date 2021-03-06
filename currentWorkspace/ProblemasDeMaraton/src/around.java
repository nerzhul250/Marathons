import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Scanner;

public class around {
	static long ways[][];
	static HashSet<String> notAllowable;
	static int N;
	public static void main(String[] args) throws IOException {
		//Scanner sc=new Scanner(System.in);
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		int c=Integer.parseInt(br.readLine());
		for (int t = 0; t < c; t++) {
			notAllowable=new HashSet<String>();
			N=Integer.parseInt(br.readLine());
			ways=new long[N+5][N+5];
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					ways[i][j]=-1;
				}
			}
			String A[]=br.readLine().split("\\s+");
			int Ax=Integer.parseInt(A[0]);
			int Ay=Integer.parseInt(A[1]);
			A=br.readLine().split("\\s+");
			int Bx=Integer.parseInt(A[0]);
			int By=Integer.parseInt(A[1]);
			
			int w=Integer.parseInt(br.readLine());
			for (int i = 0; i < w; i++) {
				A=br.readLine().split("\\s+");
				int Px=Integer.parseInt(A[0]);
				int Py=Integer.parseInt(A[1]);
				int Qx=0,Qy=0;
				char D=A[2].charAt(0);
				if(D=='N'){Qx=Px;Qy=Py+1;}
				if(D=='S'){Qx=Px;Qy=Py-1;}
				if(D=='W'){Qx=Px-1;Qy=Py;}
				if(D=='E'){Qx=Px+1;Qy=Py;}
				notAllowable.add(eval(Px,Py,Qx,Qy));
				notAllowable.add(eval(Qx,Qy,Px,Py));
			}
			bw.write(search(Ax,Ay,Bx,By)+"\n");
		}
		bw.close();
		br.close();
	}
	private static long search(int ax, int ay, int bx, int by) {
		if(ax==bx && ay==by)return 1;
		if(ways[ax][ay]!=-1)return ways[ax][ay];
		long sum=0;
		if(ax+1>=1 && ax+1<=N && ay>=1 && ay<=N && !notAllowable.contains(eval(ax,ay,ax+1,ay))){
			sum+=search(ax+1,ay,bx,by);
		}
		if(ax>=1 && ax<=N && ay+1>=1 && ay+1<=N && !notAllowable.contains(eval(ax,ay,ax,ay+1))){
			sum+=search(ax,ay+1,bx,by);
		}
		return ways[ax][ay]=sum;
	}
	private static String eval(int Px, int Py, int Qx, int Qy) {
		return "("+Px+","+Py+","+Qx+","+Qy+")";
	}
}
