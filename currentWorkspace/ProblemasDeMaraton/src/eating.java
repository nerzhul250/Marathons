import java.util.ArrayList;
import java.util.Scanner;
class Stall{
	ArrayList<Stall>neigh;
	double s;
	int index;
	public Stall(double satis,int nam) {
		index=nam;
		s=satis;
		neigh=new ArrayList<Stall>();
	}
}
class eating {
	static double ans[][];
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		Stall[] satis=new Stall[n];
		ans=new double[n][101];
		for (int i = 0; i < n; i++) {
			satis[i]=new Stall(sc.nextDouble(),i);
			for (int j = 0; j <= 100; j++) {
				ans[i][j]=-1;
			}
		}
		for (int i = 0; i <m; i++) {
			int a1=sc.nextInt();
			int a2=sc.nextInt();
			satis[a1].neigh.add(satis[a2]);
		}
		System.out.println(max(satis[0],0,1));
	}

	private static double max(Stall stal, int i, int k) {
		if(k==101)return 0;
		if(ans[i][k]>=-0.5)return ans[i][k];
		double MAX=-1;
		if(stal.neigh.isEmpty())MAX=stal.s/(Math.pow(2,k-1));
		for (int j = 0; j < stal.neigh.size(); j++) {
			Stall u=stal.neigh.get(j);
			MAX=Math.max(MAX, Math.max(max(u,u.index,k),stal.s/(Math.pow(2,k-1))+max(u,u.index,k+1)));
		}
		return ans[i][k]=MAX;
	}

}
