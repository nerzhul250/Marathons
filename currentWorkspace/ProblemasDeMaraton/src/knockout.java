import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class knockout {
	static double[][] dp;
	static int[] sums;
	static int[] scores;
	static double[] prob;
	static int totalSize;
	public static void main(String[] args) throws IOException {
		dp=new double[550][2];
		for (int i = 0; i < dp.length; i++) {
			dp[i][0]=-1;
			dp[i][1]=-1;
		}
		totalSize=(1<<9);
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] line=br.readLine().split("\\s+");
		String board=line[0];
		int sumDice=Integer.parseInt(line[1])+Integer.parseInt(line[2]);
		int bmask=getMask(board);
		initializeSums();
		initializeProbs();
		int digMax=0,digMin=0;
		double max=-Double.MAX_VALUE,min=Double.MAX_VALUE;
		boolean gotIn=false;
		for (int s = 1; s < totalSize; s++) {
			if((bmask|s)==bmask && sumDice==sums[s]) {
				gotIn=true;
				double x=getES(bmask^s,1);
				if(x>max) {max=x;digMax=s;}
				if(x<min) {min=x;digMin=s;}
				x=getES(bmask^s,0);
				if(x>max) {max=x;digMax=s;}
				if(x<min) {min=x;digMin=s;}
			}
		}
		if(!gotIn) {
			System.out.print("-1 ");
			System.out.printf("%.5f\n",scores[bmask]+0.0);
			System.out.print("-1 ");
			System.out.printf("%.5f\n",scores[bmask]+0.0);
		}else {
			System.out.print(scores[digMin]+" ");
			System.out.printf("%.5f\n",min);
			System.out.print(scores[digMax]+" ");
			System.out.printf("%.5f\n",max);
		}
	}
	

	private static double getES(int board, int j) {
		if(dp[board][j]!=-1)return dp[board][j];
		if(board==0)return 0;
		double e=0;
		double aux=0;
		int[] count=new int[13];
		double[] probs=new double[13];
		for (int s = 1; s < totalSize; s++) {
			if((board|s)==board && sums[s]<13 && 1<sums[s]) {
				aux=(prob[sums[s]]/36)*getES(board^s,j);
				if(count[sums[s]]==0){
					probs[sums[s]]=aux;
					e+=aux;
				}else {
					if(j==1) {
						if(aux>probs[sums[s]]) {
							e-=probs[sums[s]];
							e+=aux;
							probs[sums[s]]=aux;
						}
					}else {
						if(aux<probs[sums[s]]) {
							e-=probs[sums[s]];
							e+=aux;
							probs[sums[s]]=aux;
						}
					}
				}
				count[sums[s]]++;
			}
		}
		double sam=0;
		for(int i=2;i<13;i++) {
			if(count[i]==0)sam+=prob[i];
		}
		return dp[board][j]=e + (sam/36)*scores[board];
	}

	private static void initializeProbs() {
		prob=new double[13];
		prob[2]=1;
		prob[3]=2;
		prob[4]=3;
		prob[5]=4;
		prob[6]=5;
		prob[7]=6;
		prob[8]=5;
		prob[9]=4;
		prob[10]=3;
		prob[11]=2;
		prob[12]=1;
	}

	private static void initializeSums() {
		sums=new int[513];
		scores=new int[513];
		for (int s = 1; s < totalSize; s++) {
			for (int i = 1; i <=9 ; i++) {
				if((s&(1<<(i-1)))!=0) {
					sums[s]+=i;
					scores[s]*=10;
					scores[s]+=i;
				}
			}
		}
	}

	private static int getMask(String board) {
		int mask=0;
		for (int i = 0; i < board.length(); i++) {
			mask+=(1<<(board.charAt(i)-'1'));
		}
		return mask;
	}

}
