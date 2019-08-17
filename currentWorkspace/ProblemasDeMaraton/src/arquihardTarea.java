
public class arquihardTarea {

	public static void main(String[] args) {
		byte a = (byte) -Byte.parseByte("00100000", 2);
		byte b = (byte) Byte.parseByte("00011100", 2);
		byte c=(byte) (a+b);
		System.out.println(String.format("%8s", Integer.toBinaryString(c & 0xFF)).replace(' ', '0'));
		System.out.println(a);
		System.out.println(b);
		System.out.println(c);
		System.out.println("RESTA");
		c=(byte) (a-b);
		System.out.println(String.format("%8s", Integer.toBinaryString(c & 0xFF)).replace(' ', '0'));
		System.out.println(a);
		System.out.println(b);
		System.out.println(c);
	}

}
