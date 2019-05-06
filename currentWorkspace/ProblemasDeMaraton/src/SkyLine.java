import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.TreeMap;
import java.util.TreeSet;

class Point {
	int L, H, R, X;

	public Point(int l, int h, int r, int x) {
		L = l;
		H = h;
		R = r;
		X = x;
	}
}

class cmp1 implements Comparator<Point> {

	@Override
	public int compare(Point arg0, Point arg1) {
		if (arg0.X != arg1.X) {
			Integer i1 = arg0.X;
			Integer i2 = arg1.X;
			return i1.compareTo(i2);
		} else {
			if(arg0.X==arg0.L && arg1.X==arg1.L) {
				return 0;
			}else if(arg0.X==arg0.R && arg1.X==arg1.L) {
				return -1;
			}else if(arg0.X==arg0.L && arg1.X==arg1.R) {
				return 1;
			}else if(arg0.X==arg0.R && arg1.X==arg1.R) {
				return 0;
			}
			return 0;
		}
	}

}

class cmp2 implements Comparator<Point> {

	@Override
	public int compare(Point arg0, Point arg1) {
		Integer i1 = arg0.X;
		Integer i2 = arg1.X;
		return i1.compareTo(i2);
	}

}

public class Skyline {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		TreeMap<Integer,Integer> heights = new TreeMap<Integer,Integer>();
		ArrayList<Point> points = new ArrayList<Point>();
		PriorityQueue<Point> pq = new PriorityQueue<Point>(new cmp2());
		String as = "";
		while ((as = br.readLine()) != null && as.compareTo("0")!=0) {
			String[] bs = as.split("\\s+");
			int l = Integer.parseInt(bs[0]);
			int h = Integer.parseInt(bs[1]);
			int r = Integer.parseInt(bs[2]);
			points.add(new Point(l, h, r, l));
			points.add(new Point(l, h, r, r));
		}
		Collections.sort(points, new cmp1());
		int maxHeight = -1;
		int currentCoordinate = points.get(0).X;
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < points.size(); i++) {
			if (pq.peek() != null && pq.peek().X == points.get(i).X) {
				Point p = pq.remove();
				heights.put(p.H,heights.get(p.H)-1);
				if(heights.get(p.H)==0)heights.remove(p.H);
			} else {
				if(heights.containsKey(points.get(i).H)) {
					heights.put(points.get(i).H,heights.get(points.get(i).H)+1);
				}else {
					heights.put(points.get(i).H,1);
				}
				pq.add(new Point(points.get(i).L, points.get(i).H, points.get(i).R, points.get(i).R));
			}
			if (i == (points.size() - 1) || points.get(i + 1).X != currentCoordinate) {
				if (i != (points.size() - 1))currentCoordinate = points.get(i + 1).X;
				try {
					int max = heights.lastKey();
					if (max != maxHeight) {
						maxHeight = max;
						sb.append(points.get(i).X + " " + max + " ");
					}
				} catch (Exception e) {
					sb.append(points.get(i).X + " " + "0" + " ");
				}
			}
		}
		String A = sb.toString();
		A = A.substring(0, A.length() - 1);
		bw.write(A + "\n");
		bw.close();
		br.close();
	}
}
