import java.util.ArrayList;
import java.util.Collections;

public class ExesAndwuais {

	public static void main(String[] args) {
		int arr[] =new int[10];
		arr[0]=-1;
		arr[1]=0;
		arr[2]=0;
		arr[3]=0;
		arr[4]=0;
		arr[5]=0;
		arr[6]=1;
		arr[7]=0;
		arr[8]=0;
		arr[9]=0;
		int indexX=-1;
		int indexY=-1;
		for (int i = 0; i < arr.length && (indexX==-1 ||indexY==-1); i++) {
			if(indexX==-1 && arr[i]==-1)indexX=i;
			if(indexY==-1 && arr[i]==1)indexY=i;
		}
		int min=Math.abs(indexX-indexY);
		while(indexX<arr.length && indexY<arr.length) {
			if(indexX<indexY) {
				do {
					indexX++;
					if(indexX<arr.length && arr[indexX]==-1 && Math.abs(indexX-indexY)<min)min=Math.abs(indexX-indexY);
				}while(indexX<arr.length && (indexX>indexY?arr[indexX]!=-1:true));
			}else if(indexY<indexX) {
				boolean g=false;
				do {
					indexY++;
					if(indexY<arr.length && arr[indexY]==1 && Math.abs(indexX-indexY)<min)min=Math.abs(indexX-indexY);
					g=indexY<arr.length;
					g=g&&(indexX<indexY?(arr[indexY]!=1):true);
					System.out.println(g);
				}while(g);
			}
		}
		System.out.println(min);
	}

}
