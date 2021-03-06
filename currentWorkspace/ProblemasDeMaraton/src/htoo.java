import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

class htoo {

	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		String[] A=br.readLine().split("\\s+");
		A[0]+="A";
		StringBuilder sb=new StringBuilder();
		for (int i = 0; i < A[0].length()-1; i++) {
			if(A[0].charAt(i)<='Z' &&A[0].charAt(i)>='A' &&A[0].charAt(i+1)<='Z' &&A[0].charAt(i+1)>='A') {
				sb.append(A[0].charAt(i)+"1");
			}else {
				sb.append(A[0].charAt(i));
			}
		}
		int mult=Integer.parseInt(A[1]);
		int[] word1 =new int[30];
		A=clean(sb.toString().split("[A-Z]+"));
		String[] B=clean(sb.toString().split("[0-9]+"));
		for (int i = 0; i < B.length; i++) {
			word1[B[i].charAt(0)-'A']+=Integer.parseInt(A[i])*mult;
		}
		String com=br.readLine();
		com+="A";
		sb=new StringBuilder();
		for (int i = 0; i < com.length()-1; i++) {
			if(com.charAt(i)<='Z' &&com.charAt(i)>='A' &&com.charAt(i+1)<='Z' &&com.charAt(i+1)>='A') {
				sb.append(com.charAt(i)+"1");
			}else {
				sb.append(com.charAt(i));
			}
		}
		int word2[]=new int[30];
		A=clean(sb.toString().split("[A-Z]+"));
		B=clean(sb.toString().split("[0-9]+"));
		for (int i = 0; i < B.length; i++) {
			word2[B[i].charAt(0)-'A']+=Integer.parseInt(A[i]);
		}
		int min=Integer.MAX_VALUE;
		for (int i = 0; i < word2.length; i++) {
			if(word2[i]>0) {
				int quant=word1[i]/word2[i];
				if(quant<min)min=quant;
			}
		}
		System.out.println(min);
	}

	private static String[] clean(String[] split) {
		ArrayList<String>k=new ArrayList<String>();
		for (int i = 0; i < split.length; i++) {
			if(!split[i].isEmpty())k.add(split[i]);
		}
		String[] a=new String[k.size()];
		for (int i = 0; i < a.length; i++)a[i]=k.get(i);
		return a;
	}

}
