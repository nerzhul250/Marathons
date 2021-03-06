import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.TreeSet;
class cmp implements Comparator<String>{

	@Override
	public int compare(String arg0, String arg1) {
		String A[]=arg0.split("\\+");
		String B[]=arg1.split("\\+");
		int max=A.length>B.length?A.length:B.length;
		for (int i = 0; i < max; i++) {
			if(i>=B.length)return 1;
			if(i>=A.length)return -1;
			if(A[i].compareTo(B[i])==1)return -1;
			if(A[i].compareTo(B[i])==-1)return 1;
		}
		return 0;
	}
	
}
public class SumItUp {
	static StringBuilder sb;
	static TreeSet<String> set;
	public static void main(String[] args) throws IOException {
		//BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		Scanner sc=new Scanner(System.in);
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		int t=sc.nextInt();
		int n=sc.nextInt();
		//String[] line=br.readLine().split("\\s+");
		while(n!=0) {
			//int t=Integer.parseInt(line[0]);
			//int n=Integer.parseInt(line[1]);
			set=new TreeSet<String>(new cmp());
			int[] nums=new int[n];
			for (int i = 0; i < n; i++)nums[i]=sc.nextInt();
			int totalSize=(1<<n);
			boolean gotIn=false;
			bw.write("Sums of "+t+":\n");
			for (int mask = 1; mask < totalSize; mask++) {
				int sum=0;
				int index=0;
				int amount=1;
			    sb=new StringBuilder();
				while(amount<totalSize) {
					if((amount&mask)!=0) {
						sb.append(nums[index]+"+");
						sum+=nums[index];
					}
					index++;
					amount=amount<<1;
				}
				String g=sb.toString();
				g=g.substring(0,g.length()-1);
				if(sum==t && !set.contains(g)) {
					gotIn=true;
					set.add(g);
				}
			}
			if(!gotIn) {bw.write("NONE\n");}else {
				Iterator<String>it=set.iterator();
				while(it.hasNext()) {
					bw.write(it.next()+"\n");					
				}
			}
			t=sc.nextInt();
			n=sc.nextInt();
		}
		bw.close();
	}
}