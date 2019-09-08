
public class ArquihardTesting {

	public static void main(String[] args) {
		float f=(float)(1/2.0 + 1/2048.0);
		float f2=0;
		while(f2!=f+f2) {
			f2+=f;
		}
		System.out.println(f2);
		System.out.println(f2+f);
		System.out.println(Double.toHexString(f2));
	}

}
