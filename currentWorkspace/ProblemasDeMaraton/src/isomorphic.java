import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.TreeSet;

class Wrapper{
	LinkedList<Character> word;
	int hashCode;
	int power;
	int mod;
	public Wrapper() {
		word=new LinkedList<Character>();
		power=1;
		mod=1299827;
	}
	public void addLeft(char c) {
		int a=c;
		hashCode=(hashCode+a*power)%mod;
		power=(power*101)%mod;
		word.addLast(c);
	}
	public void addRight(char c) {
		int a=c;
		hashCode=(hashCode*101+a)%mod;
		word.addFirst(c);
	}
	public int getSize() {
		return word.size();
	}
	@Override
	public int hashCode() {
		return hashCode;
	}
	@Override
	public boolean equals(Object arg0) {
		Wrapper w=(Wrapper) arg0;
		if(getSize()!=w.getSize())return false;
		Iterator<Character> it1=word.iterator();
		Iterator<Character> it2=w.word.iterator();
		while(it1.hasNext()) {
			char a1=it1.next();
			char a2=it2.next();
			if(a1!=a2)return false;
		}
		return true;
	}
	@Override
	public String toString() {
		Iterator<Character> it1=word.iterator();
		StringBuilder sb=new StringBuilder();
		while(it1.hasNext()) {
			sb.append(it1.next());
		}
		return sb.toString();
	}
}
class isomorphic {

	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		String word=br.readLine();
		int leftMostPalindrome=0,rightMostPalindrome=word.length()-1;
		int k=0;
		HashSet<Wrapper> words;
		while(leftMostPalindrome<rightMostPalindrome) {
			words=new HashSet<Wrapper>();
			int il=leftMostPalindrome,ir=rightMostPalindrome;
			Wrapper w1=new Wrapper(),w2=new Wrapper();
			w1.addLeft(word.charAt(il)); w2.addRight(word.charAt(ir));
			words.add(w1);
			while(!words.contains(w2)&&il+1<ir-1) {
				il++;
				ir--;
				w1.addLeft(word.charAt(il));
				w2.addRight(word.charAt(ir));
				words=new HashSet<Wrapper>();
				words.add(w1);
			}
			leftMostPalindrome=il+1;
			rightMostPalindrome=ir-1;
			if(words.contains(w2)) {
				k+=2;				
				if(leftMostPalindrome==rightMostPalindrome)k++;
			}else {
				k++;
				leftMostPalindrome=rightMostPalindrome;
			}
		}
		if(word.length()==1)k++;
		System.out.println(k);
	}

}
