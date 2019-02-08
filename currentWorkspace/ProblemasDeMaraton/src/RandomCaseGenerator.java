import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class RandomCaseGenerator {

	public static void main(String[] args) throws IOException {
		BufferedWriter bw=new BufferedWriter(new FileWriter("..\\tests.txt"));
		int N=100000;
		int F=5;
		bw.write(N+" "+F+"\n");
		for (int i = 1; i <= N-1; i++) {
			bw.write(i+" "+(i+1)+" "+"10\n");
		}
		String a="";
		for (int i = 1; i <= F; i++) {
			a+=i*2+" ";
		}
		bw.write(a.trim()+"\n");
		bw.close();
	}

}
