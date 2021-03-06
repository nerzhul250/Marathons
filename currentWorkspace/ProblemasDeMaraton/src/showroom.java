import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;

public class showroom {
	static node[][] building;
	static int R;
	static int C;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] A=br.readLine().split("\\s+");
		R=Integer.parseInt(A[0]);
		C=Integer.parseInt(A[1]);
		building=new node[R][C];
		for (int i = 0; i < R; i++) {
			char [] x = br.readLine().toCharArray();
			for (int j = 0; j < C; j++){
				building[i][j] = new node(x[j], i, j);
			}
		}
		A=br.readLine().split("\\s+");
		int or=Integer.parseInt(A[0])-1;
		int oc=Integer.parseInt(A[1])-1;
		System.out.println(bfs(or, oc)+1);
	}
	
	public static int bfs (int or, int oc){
		int candSolve = Integer.MAX_VALUE;
		PriorityQueue<node> prior = new PriorityQueue<>();
		prior.add(building[or][oc]);
		(building[or][oc]).marked = 1;
		(building[or][oc]).count = 0;
		while (!prior.isEmpty()){
			node x = prior.poll();
			x.marked=2;
			if (x.x == 0 || x.y == 0 || x.x == building.length - 1 || x.y == building[0].length - 1){
				if (building[x.x][x.y].symb == 'D')
					candSolve = Math.min(candSolve, x.count);
			} 
			if (x.y < building[0].length - 1){
				node cand = building[x.x][x.y+1];
				if (cand.symb != '#' && cand.marked!=2){
					if(cand.count>cand.peso+x.count)cand.count=cand.peso+x.count;
					if(cand.marked==0) {
						cand.marked=1;
						prior.add(cand);
					}
				}
			}
				if (x.x > 0){
					node cand = building[x.x-1][x.y];
					if (cand.symb != '#' && cand.marked!=2){
						if(cand.count>cand.peso+x.count)cand.count=cand.peso+x.count;
						if(cand.marked==0) {
							cand.marked=1;
							prior.add(cand);
						}
					}
				}
				if (x.x < building.length - 1){
					node cand = building[x.x+1][x.y];
					if (cand.symb != '#' && cand.marked!=2){
						if(cand.count>cand.peso+x.count)cand.count=cand.peso+x.count;
						if(cand.marked==0) {
							cand.marked=1;
							prior.add(cand);
						}
					}
				}
				if (x.y > 0){
					node cand = building[x.x][x.y - 1];
					if (cand.symb != '#' && cand.marked!=2){
						if(cand.count>cand.peso+x.count)cand.count=cand.peso+x.count;
						if(cand.marked==0) {
							cand.marked=1;
							prior.add(cand);
						}
					}
				}
				
			}
			
		return candSolve;
	}
}

class node implements Comparable<node>{
	char symb;
	int peso;
	int x;
	int y;
	int count;
	int marked;
	node (char s, int x, int y){
		symb = s;
		peso = s == 'c' ? 1 : 0;
		marked = 0;
		count = Integer.MAX_VALUE;
		this.x = x;
		this.y = y;
	}
	@Override
	public int compareTo(node o) {
		return count - o.count;
	}
	
}
