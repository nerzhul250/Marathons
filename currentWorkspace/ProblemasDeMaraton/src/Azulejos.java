import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class Azulejo implements Comparable<Azulejo>{
	int id;
	int price;
	int height;
	public Azulejo(int p,int h,int i) {
		price=p;
		height=h;
		id=i;
	}
	@Override
	public int compareTo(Azulejo a) {
		Integer p1=price;
		Integer p2=a.price;
		int com1=p1.compareTo(p2);
		if(com1==0) {
			Integer h1=height;
			Integer h2=a.height;
			return h2.compareTo(h1);
		}else {return com1;}
	}
	
}
public class Azulejos {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[][] info=new int[4][n];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < n; j++) {
				info[i][j]=sc.nextInt();
			}
		}
		ArrayList<Azulejo> firstRow=new ArrayList<Azulejo>();
		ArrayList<Azulejo> secondRow=new ArrayList<Azulejo>();
		for (int i = 0; i < n; i++) {
			firstRow.add(new Azulejo(info[0][i],info[1][i],i+1));
			secondRow.add(new Azulejo(info[2][i],info[3][i],i+1));
		}
		Collections.sort(firstRow);
		Collections.sort(secondRow);
		boolean possible=true;
		for (int i = 0; i < n && possible; i++) {
			if(firstRow.get(i).height<=secondRow.get(i).height)possible=false;
		}
		if(possible) {
			StringBuilder sb=new StringBuilder();
			for (int i = 0; i <n; i++) {
				if(i<n-1) {
					sb.append(firstRow.get(i).id+" ");					
				}else {
					sb.append(firstRow.get(i).id+"\n");					
				}
			}
			for (int i = 0; i <n; i++) {
				if(i<n-1) {
					sb.append(secondRow.get(i).id+" ");					
				}else {
					sb.append(secondRow.get(i).id+"\n");					
				}
			}
			System.out.print(sb.toString());
		}else {
			System.out.println("impossible");
		}
	}

}
