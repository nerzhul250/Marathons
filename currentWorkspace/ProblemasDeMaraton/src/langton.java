import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class langton {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String data = br.readLine();
		
		while (!data.equals("0 0 0 0")) {
			String [] initData = data.split(" ");
			int n = Integer.parseInt(initData[0]);
			int c = Integer.parseInt(initData[1]);
			int x  = Integer.parseInt(initData[2]);
			int y = Integer.parseInt(initData[3]);
			
			int toX = 0;
			int toY = -1;
			
			String state = Integer.toBinaryString(c);
			
			boolean [][] matrix = new boolean [n][n];
			
			StringBuilder builder = new StringBuilder();
			
			for (int i = 0; i < n*n - state.length(); i++) {
				builder.append("0");
			}
			builder.append(state);
			
			state = builder.toString();
			
			for (int i = 0; i < state.length(); i++) {
				int invRow = i / n;
				int realRow = n - invRow - 1;
				
				int column = i % n;
				
				matrix[realRow][invRow] = state.charAt(i) == 1;
			}
			
			x = n - x;
			y -= 1;
			
			int objectiveX = 0;
			int objectiveY = n - 1;
			
			boolean dead = false;
			
			
			while (x != objectiveX && y != objectiveY && !dead) {
				if (matrix[x][y]) {
					matrix[x][y] = !matrix[x][y];
					if (toY == 0) {
						
						if (toX == 1) {
							toY = 1;
						} else {
							toY = -1;
						}
						toX = 0;
					} else {
						matrix[x][y] = !matrix[x][y];
						if (toY == -1) {
							toX = 1;
						} else {
							toX  = -1;
						}
						toY = 0;
					}
					
					
				} else {
					matrix[x][y] = !matrix[x][y];
					if (toY == 0) {
						
						if (toX == 1) {
							toY = -1;
						} else {
							toY = 1;
						}
						toX = 0;
					} else {
						matrix[x][y] = !matrix[x][y];
						if (y == -1) {
							toX = -1;
						} else {
							toX  = 1;
						}
						toY = 0;
					} 
				}
				
				x += toX;
				y += toY;
				try {
					boolean a = matrix[x][y];
				} catch (Exception e) {
					dead = true;
				}
			}
			
			if (dead) {
				bw.write("Kaputt!\n");
			} else {
				bw.write("Yes\n");
			}
					
			
			data = br.readLine();
		}
		
		
		
		bw.close();
	}

}
