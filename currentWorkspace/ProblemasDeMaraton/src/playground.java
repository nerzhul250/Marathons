import java.util.Collections;
import java.util.Scanner;

public class playground {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int B=Integer.parseInt(sc.nextLine());
		int H=Integer.parseInt(sc.nextLine());
		char[] A;
		String[] BB=sc.nextLine().split("\\s+");
		int r=Integer.parseInt(BB[0]);
		int c=Integer.parseInt(BB[1]);
		int[][] binarydisco=new int[r][c];
		double[][] disco=new double[r][c];
		double[][] disco2=new double[r][c];
		for (int i = 0; i < r; i++) {
			A=sc.nextLine().toCharArray();
			for (int j = 0; j < c; j++) {
				disco[i][j]=A[j] - '0';
			}
		}
		for (int i = 0; i < disco.length; i++) {
			for (int j = 0; j < disco[0].length; j++) {
				for (int j2 = 0; j2 < disco.length; j2++) {
					for (int k = 0; k < disco[0].length; k++) {
						disco2[j2][k]+=computeLight(disco[i][j],(double)(j-k),(double)(i-j2),(double)H);
					}
				}
			}
		}
		for (int i = 0; i < disco2.length; i++) {
			for (int j = 0; j < disco2[0].length; j++) {
				if(disco2[i][j]>=B) {
					binarydisco[i][j]=1;
				}
				System.out.print(binarydisco[i][j]);
			}
			System.out.println("");
		}
	}

	private static double computeLight(double s, double x, double y, double z) {
		return s/(x*x+y*y+z*z);
	}

}
