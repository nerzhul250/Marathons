import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.TreeSet;

import javax.swing.plaf.FontUIResource;

public class subsets {

	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		TreeSet<Integer>arbol=new TreeSet<Integer>();
		HashMap<Integer,Integer>nToI=new HashMap<Integer,Integer>();
		String[] A=br.readLine().split("\\s+");
		int n=Integer.parseInt(A[0]);
		int q=Integer.parseInt(A[1]);
		int[] nums=new int[n];
		for (int i = 0; i < n; i++) {
			int x=Integer.parseInt(br.readLine());
			arbol.add(x);
			nums[i]=x;
		}
		Arrays.sort(nums);
		for (int i = 0; i < nums.length; i++) {
			nToI.put(nums[i],i);
		}
		int counter=0;
		int indexOnSet=0;
		int[] queries=new int[q];
		for (int i = 0; i < queries.length; i++) {
			queries[i]=Integer.parseInt(br.readLine());
		}
		Arrays.sort(queries);
		for (int i = 0; i < q; i++) {
			Integer smallest=null;
			smallest=indexOnSet>=nums.length?null:arbol.floor(queries[i]-nums[indexOnSet]);
			while(smallest!=null) {
				int index=nToI.get(smallest);
				if(index<indexOnSet) {
					counter+=index+1;
				}else {
					counter+=indexOnSet;
				}
				indexOnSet++;
				System.out.println(counter+" "+queries[i]+" "+nums[indexOnSet]);
				smallest=(indexOnSet>=nums.length?null:arbol.floor(queries[i]-nums[indexOnSet]));
			}
			bw.write(counter+"\n");
		}
		bw.close();
		br.close();
	}

}
