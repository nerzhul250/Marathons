import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;

class Node{
	int nodeNumber;
	boolean additive;
	ArrayList<Node> children;
	int cost;
	int accumulatedCost;
	public Node(int nn) {
		nodeNumber=nn;
		additive=false;
		children=new ArrayList<Node>();
		cost=0;
		accumulatedCost=0;
	}
}
public class IntrepidClimber {
	static HashMap<Integer,Node>nodes;
	public static void main(String[] args) throws IOException {
		//BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br=new BufferedReader(new FileReader("..\\tests.txt"));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		String A=br.readLine();
		while(A!=null && !A.isEmpty()) {
			String[] B=A.split("\\s+");
			int N=Integer.parseInt(B[0]);
			int F=Integer.parseInt(B[1]);
			nodes=new HashMap<Integer,Node>();
			for (int i = 0; i < N-1; i++) {
				B=br.readLine().split("\\s+");
				int a=Integer.parseInt(B[0]); Node aa=null;
				int b=Integer.parseInt(B[1]); Node bb=null;
				int c=Integer.parseInt(B[2]);
				if(!nodes.containsKey(a)) {
					aa=new Node(a);
					nodes.put(a,aa);
				}else {
					aa=nodes.get(a);
				}
				if(!nodes.containsKey(b)) {
					bb=new Node(b);
					nodes.put(b,bb);
				}else {
					bb=nodes.get(b);
				}
				bb.cost=c;
				aa.children.add(bb);
			}
			B=br.readLine().split("\\s+");
			for (int i = 0; i < F; i++) {
				nodes.get(Integer.parseInt(B[i])).additive=true;
			}
			accumulativeCosts(1);
			bw.write(minimumCost(1,0)+"\n");
			A=br.readLine();
		}
		bw.close();
		br.close();
	}

	private static int minimumCost(int node,int minCost) {
		Node n=nodes.get(node);
		if(n.children.isEmpty()) {
			return minCost;
		}else {
			int maximum=Integer.MIN_VALUE;
			int index=0;
			for (int i = 0; i < n.children.size(); i++) {
				if(n.children.get(i).additive) {
					int cost=n.children.get(i).accumulatedCost+n.children.get(i).cost;
					if(cost>maximum) {
						index=i;
						maximum=cost;
					}
					minCost+=cost;
				}
			}
			if(maximum!=Integer.MIN_VALUE) {
				minCost=minCost-maximum;
				return minimumCost(n.children.get(index).nodeNumber,minCost);
			}else {
				return minCost;
			}
		}
	}
	private static void accumulativeCosts(int node) {
		System.out.println(node);
		Node n=nodes.get(node);
		if(!n.children.isEmpty()) {
			for (int i = 0; i < n.children.size(); i++) {
				accumulativeCosts(n.children.get(i).nodeNumber);
				n.additive=n.additive||n.children.get(i).additive;
				if(n.children.get(i).additive) {
					n.accumulatedCost+=n.children.get(i).cost+n.children.get(i).accumulatedCost;
				}
			}
		}
	}
}