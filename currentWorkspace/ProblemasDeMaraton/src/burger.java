import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class burger {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw= new BufferedWriter(new OutputStreamWriter(System.out));
		int num= Integer.parseInt(br.readLine());
		while(num != 0) {
			char[] paths= br.readLine().toCharArray();
			char lastCharacter= ' ';
			int minimunDis= Integer.MAX_VALUE;
			int start=0;
			for(int i=0;i<paths.length;i++) {
				if(paths[i]=='Z') {
					start= Integer.MAX_VALUE;
				}
			}
			if(start!= Integer.MAX_VALUE) {
				
				for(int i=0;i<paths.length;i++) {
					if(paths[i]=='D'|| paths[i]=='R') {
						start=i;
						lastCharacter=paths[i];
						break;
					}
				}
			}
			if(start!= Integer.MAX_VALUE) {
				for(int i=start+1;i<paths.length;i++) {
					
					if(paths[i]==lastCharacter) {
						start = i;
					}else if(paths[i]!='.') {
						if(i-start<minimunDis) {
							minimunDis= i-start;
							start=i;
							lastCharacter= paths[i];
						}else {
							start=i;
							lastCharacter= paths[i];
						}
					}
				}
				bw.write(minimunDis+"\n");
				
			}else {
				bw.write("0"+"\n");
			}
			num= Integer.parseInt(br.readLine());
		}
		bw.close();

	}

}
