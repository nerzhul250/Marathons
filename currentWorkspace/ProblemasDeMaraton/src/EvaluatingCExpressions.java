import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;

import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;

public class EvaluatingCExpressions {

	public static void main(String[] args) throws ScriptException, IOException {
		ScriptEngineManager mgr = new ScriptEngineManager();
		ScriptEngine engine = mgr.getEngineByName("JavaScript"); // "cheat"
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		while(true) {
			String exp=br.readLine();
			if(exp==null || exp.isEmpty())break;
			String org=exp;
			int[] values=new int[26];
			int[] toSum=new int[26];
			boolean[] aparece=new boolean[26];
			for(int i=0;i<26;i++)values[i]=i+1;
			exp=exp.replaceAll("\\s+","");
			for(int i=0;i<26;i++) {
				if(exp.indexOf((char)('a'+i)+"")!=-1)aparece[i]=true;
				if(exp.indexOf("--"+(char)('a'+i))!=-1) {
					values[i]--;
					exp=exp.replaceAll("--"+(char)('a'+i),(char)('a'+i)+"");
				}else if(exp.indexOf("++"+(char)('a'+i))!=-1) {
					values[i]++;
					exp=exp.replaceAll("\\+\\+"+(char)('a'+i),(char)('a'+i)+"");
				}
			}
			
			for(int i=0;i<26;i++) {
				if(exp.indexOf((char)('a'+i)+"--")!=-1) {
					toSum[i]=-1;
					exp=exp.replaceAll((char)('a'+i)+"--",(char)('a'+i)+"");
				}else if(exp.indexOf((char)('a'+i)+"++")!=-1) {
					toSum[i]=1;
					exp=exp.replaceAll((char)('a'+i)+"\\+\\+",(char)('a'+i)+"");
				}
			}
			
			for(int i=0;i<26;i++) {
				String f=((char) ('a'+i))+"";
				String s=(values[i])+"";
				exp=exp.replaceAll(f,s);			
			}
			bw.write("Expression: "+org+"\n");
			bw.write("    value = "+engine.eval(exp)+"\n");
			for(int i=0;i<26;i++) {
				values[i]+=toSum[i];
				if(aparece[i]) {
					bw.write("    "+(char)('a'+i)+" = "+values[i]+"\n");
				}
			}
		}
		bw.close();
		br.close();
		
	}

}
