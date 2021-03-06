import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class appalling {

	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		String[] A=br.readLine().split("\\s+");
		int h=Integer.parseInt(A[0]);
		int w=Integer.parseInt(A[1]);
		int[] nam=new int[w];
		double xleft=0,xright=0;
		for (int i = 0; i < h; i++) {
			char[] symbols=br.readLine().toCharArray();
			for (int j = 0; j < symbols.length; j++) {
				if(symbols[j]!='.') {
					nam[j]++;
				}
			}
			if(i==h-1) {
				for (int j = 0; j < symbols.length; j++) {
					if(symbols[j]!='.') {
						xleft=j;
						break;
					}
				}
				for (int j = symbols.length-1; j>=0; j--) {
					if(symbols[j]!='.') {
						xright=j;
						break;
					}
				}
			}
		}
		xleft-=0.5;
		xright+=0.5;
		double xGravity=0;
		int count=0;
		for (int i = 0; i < nam.length; i++) {
			xGravity+=i*nam[i];
			count+=nam[i];
		}
		xGravity/=count;
		if(xGravity<xleft) {
			System.out.println("left");
		}else if(xright<xGravity) {
			System.out.println("right");
		}else {
			System.out.println("balanced");
		}
	}

}
