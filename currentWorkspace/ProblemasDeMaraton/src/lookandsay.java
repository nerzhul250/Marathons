import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class lookandsay {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] line= br.readLine().split("\\s+");
		while(!line[0].equals("0")) {
			String currentSeq=line[0];
			int limith=Integer.parseInt(line[1]);
			int j=Integer.parseInt(line[2]);
			j--;
			for (int k = 2; k <=limith; k++) {
				currentSeq=transform(currentSeq);
			}
			bw.write(currentSeq.charAt(j)+"\n");
			line= br.readLine().split("\\s+");
		}
				
		bw.close();
	}
	
	public static String transform(String s) {
		int counter=1;
		char currentNumber= s.charAt(0);
		StringBuilder res=new StringBuilder();
		for(int i=1;i<s.length() && i<=1000;i++) {
			if(s.charAt(i)== currentNumber) {
				counter++;
			}else {
				res.append(counter);
				res.append(currentNumber);
				currentNumber= s.charAt(i);
				counter =1;
			}
		}
		res.append(counter+""+currentNumber);
		return res.toString();
	}



}
