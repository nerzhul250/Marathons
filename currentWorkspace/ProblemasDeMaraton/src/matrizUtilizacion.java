import java.util.Scanner;

public class matrizUtilizacion {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int[][] tabla=new int[11][11];
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 10; j++) {
				tabla[i][j]=sc.nextInt();
			}
			tabla[i][10]=sc.nextInt();
		}
		int[][] newTable=new int[10][10];
		for (int i = 0; i < newTable.length; i++) {
			for (int j = 0; j < newTable.length; j++) {
				int sum=0;
				for (int k = 0; k < 11; k++) {
					if(tabla[k][i]==tabla[k][j] && tabla[k][i]==1 ) {
						sum+=tabla[k][10];
					}
				}
				newTable[i][j]=sum;
			}
		}
		for (int i = 0; i < newTable.length; i++) {
			for (int j = 0; j < newTable.length; j++) {
				String palabra=newTable[i][j]+"";
				if(palabra.length()==2) {
					System.out.print(palabra+"  ");
				}else {
					System.out.print(palabra+" ");
				}
			}
			System.out.println("");
		}
	}

}
