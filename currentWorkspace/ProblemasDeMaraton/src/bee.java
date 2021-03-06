import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

class Hexagon{
	int i,j;
	Hexagon[] neighbors;
	char symbol;
	boolean visited;
	public Hexagon(char s,int is, int js) {
		neighbors=new Hexagon[6];
		symbol=s;
		visited=false;
		i=is;
		j=js;
	}
}
class bee {

	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		String[] A=br.readLine().split("\\s+");
		int h=Integer.parseInt(A[0]);
		int n=Integer.parseInt(A[1]);
		int m=Integer.parseInt(A[2]);
		Hexagon[][] hive=new Hexagon[n][m*2];
		for (int i = 0; i < n; i++) {
			char[] line=br.readLine().toCharArray();
			for (int j = 0; j < line.length; j++) {
				if(line[j]!=' ' && line[j]!='#')hive[i][j]=new Hexagon(line[j],i,j);
			}
		}
		for (int i = 0; i < hive.length; i++) {
			for (int j = 0; j < hive[0].length; j++) {
				if(hive[i][j]!=null) {
					setUpNeighbors(i,j,hive);
				}
			}
		}
		ArrayList<Integer> components=new ArrayList<Integer>();
		for (int i = 0; i < hive.length; i++) {
			for (int j = 0; j < hive[0].length; j++) {
				if(hive[i][j]!=null && !hive[i][j].visited) {
					int number=recorrido(hive[i][j]);
					components.add(number);
				}
			}
		}
		Collections.sort(components);
		int counter=0;
		int sum=0;
		for (int i = components.size()-1; i >=0; i--) {
			sum+=components.get(i);
			counter++;
			if(sum>=h)break;
		}
		if(h==0) {
			System.out.println(0);
		}else {
			System.out.println(counter);			
		}
	}

	private static Integer recorrido(Hexagon h) {
		h.visited=true;
		int sum=0;
		Queue<Hexagon> cola=new LinkedList<Hexagon>();
		cola.add(h);
		h.visited=true;
		sum++;
		while(!cola.isEmpty()) {
			Hexagon u=cola.remove();
			for (int i = 0; i < u.neighbors.length; i++) {
				if(u.neighbors[i]!=null&&!u.neighbors[i].visited) {
					cola.add(u.neighbors[i]);
					u.neighbors[i].visited=true;
					sum++;
				}
			}
		}
		return sum;
	}

	private static void setUpNeighbors(int i, int j, Hexagon[][] hive) {
		if(valid(i,j+2,hive)) {
			hive[i][j].neighbors[0]=hive[i][j+2];
		}
		if(valid(i+1,j+1,hive)) {
			hive[i][j].neighbors[1]=hive[i+1][j+1];
		}
		if(valid(i+1,j-1,hive)) {
			hive[i][j].neighbors[2]=hive[i+1][j-1];
		}
		if(valid(i,j-2,hive)) {
			hive[i][j].neighbors[3]=hive[i][j-2];
		}
		if(valid(i-1,j-1,hive)) {
			hive[i][j].neighbors[4]=hive[i-1][j-1];
		}
		if(valid(i-1,j+1,hive)) {
			hive[i][j].neighbors[5]=hive[i-1][j+1];
		}
	}

	private static boolean valid(int i, int j, Hexagon[][] hive) {
		return i<hive.length && i>=0 && j<hive[0].length && j>=0 && hive[i][j]!=null;
	}

}
