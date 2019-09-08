import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.LinkedList;
import java.util.Queue;

public class IPV6 {

	public static void main(String[] args) throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String number = br.readLine();
		while(number != null&&!number.contentEquals("")) {
			String hexa = convertToHexa32Digits(number);
			Queue<String> sections= new LinkedList<String>();
			for(int i=0;i<hexa.length();i+=4) {
				StringBuilder currentSection= new StringBuilder();
				for(int j=0;j<4;j++) {
					currentSection.append(hexa.charAt(i+j));
				}
				if(currentSection.toString().contentEquals("0000")) {
					sections.add("0");
				}else {
					String ans=currentSection.toString();
					if(ans.charAt(0)=='0') {
						ans= pruningFirstZeroes(ans);
					}
					sections.add(ans);
				}
			}
			
			bw.write(finalFormat(sections)+"\n");
			number= br.readLine();
		}
		bw.close();

	}
	public static String pruningFirstZeroes(String n) {
		boolean isTheFirstZero=true;
		String ans="";
		for(int i=0;i<n.length();i++) {
			if(isTheFirstZero && n.charAt(i)=='0') {
				
			}else {
				ans+=n.charAt(i);
				isTheFirstZero=false;
			}
		}
		return ans;
	}
	public static String finalFormat(Queue<String> sections) {
		StringBuilder ans= new StringBuilder();
		boolean theLastOneWasZero= false;
		int numberOfZeroes=0;
		boolean doIputHexDifferentOfZero=false;
		while(!sections.isEmpty()) {
			String currentSection= sections.poll();
			if(currentSection.contentEquals("0")) {
				theLastOneWasZero=true;
				numberOfZeroes++;
			}else {
				if(theLastOneWasZero) {
					if(numberOfZeroes==1) {
						ans.append(currentSection+":");
						theLastOneWasZero=false;
						numberOfZeroes=0;
					}else if(numberOfZeroes>1) {
						if(doIputHexDifferentOfZero) {
							ans.append(":");
						}else {
							ans.append("::");
						}
						
						theLastOneWasZero=false;
						numberOfZeroes=0;
					}
				}
				doIputHexDifferentOfZero=true;
				if(sections.isEmpty()) {
					ans.append(currentSection);
				}else {
					ans.append(currentSection+":");					
				}
			}
			
		}
		if(theLastOneWasZero&& numberOfZeroes>1) {
			ans.append("::");
		}else if(theLastOneWasZero) {
			ans.append("0");
		}
		return ans.toString();
	}
	public static String convertToHexa32Digits(String n) {
		StringBuilder num= new StringBuilder(new BigInteger(n).toString(16));
		if(num.length()<32) {
			int zeroesToComplete = 32-num.length();
			while(zeroesToComplete >0) {
				num.insert(0, '0');
				zeroesToComplete--;
			}
		}
		return num.toString();
	}

}
