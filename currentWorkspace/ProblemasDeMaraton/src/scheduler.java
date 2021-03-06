import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class scheduler {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int c=sc.nextInt();
		int[] times=new int[n];
		Queue<Integer> shoppers=new LinkedList<Integer>();
		for (int i = 0; i < c; i++) {
			shoppers.add(sc.nextInt());
		}
		int min=Integer.MAX_VALUE;
		StringBuilder sb=new StringBuilder();
		for (int i = 0; i < times.length; i++) {
			times[i]=shoppers.remove();
			sb.append((i+1)+" ");
			if(times[i]<min)min=times[i];
		}
		try {
			while(!shoppers.isEmpty()) {
				for (int i = 0; i < times.length; i++)times[i]-=min;
				for (int i = 0; i < times.length; i++) {
					if(times[i]<=0) {
						times[i]=shoppers.remove();
						sb.append((i+1)+" ");
					}
				}
				min=Integer.MAX_VALUE;
				for (int i = 0; i < times.length; i++) {
					if(times[i]<min)min=times[i];
				}
			}
		}catch(Exception e) {
			
		}
		String A=sb.toString();
		A=A.substring(0,A.length()-1);
		System.out.println(A);
	}

}
