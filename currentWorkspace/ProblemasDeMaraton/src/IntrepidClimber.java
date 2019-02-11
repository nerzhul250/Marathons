import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;

class Node{
	int nodeNumber;
	boolean additive;
	boolean visited;
	ArrayList<Node> children;
	Node parent;
	int cost;
	int accumulatedCost;
	public Node(int nn) {
		additive=false;
		visited=false;
		nodeNumber=nn;
		parent=null;
		children=new ArrayList<Node>();
		cost=0;
		accumulatedCost=0;
	}
}
public class IntrepidClimber {
	static HashMap<Integer,Node>nodes;
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		//BufferedReader br=new BufferedReader(new FileReader("..\\tests.txt"));
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
				bb.parent=aa;
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
		while(true) {
			if(n.children.isEmpty()) {
				break;
			}else{
				int maximum=Integer.MIN_VALUE;
				int index=-1;
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
				if(maximum!=Integer.MIN_VALUE && index!=-1) {
					minCost=minCost-maximum;
					n=n.children.get(index);
				}else {
					break;
				}
			}
		}
		return minCost;
	}
	private static void accumulativeCosts(int node) {
		LinkedList<Node> stackNodes=new LinkedList<Node>();
		stackNodes.addFirst(nodes.get(node));
		while(!stackNodes.isEmpty()) {
			Node first=stackNodes.getFirst();
			if(!first.visited) {
				first.visited=true;
				if(!first.children.isEmpty()) {
					for (int i = 0; i < first.children.size(); i++) {
						stackNodes.addFirst(first.children.get(i));
					}
				}else {
					if(first.additive) {
						first.parent.accumulatedCost+=first.cost+first.accumulatedCost;
						first.parent.additive=true;
					}
					stackNodes.removeFirst();
				}
			}else {
				if(first.additive && first.nodeNumber!=1) {
					first.parent.accumulatedCost+=first.cost+first.accumulatedCost;
					first.parent.additive=true;
				}
				stackNodes.removeFirst();
			}
		}
	}
}