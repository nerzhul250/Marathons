import java.io.InputStreamReader;
import java.util.Scanner;

public class OrzPandas {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()) {
			double x0 = sc.nextInt();
			double y0 = sc.nextInt();
			double x1 = sc.nextInt();
			double y1 = sc.nextInt();
			double vmax = sc.nextInt();
			
			double x = x1 - x0;
			double y = y1 - y0;
			double g = 9.80665;
			
			if(x==0 && y==0) {
				System.out.println("0 0 0");
			}else {
				double delta = Math.sqrt(Math.pow(y*g - vmax*vmax, 2) - g*g*(x*x+y*y));
				
				double t = 2*(vmax*vmax - g*y - delta)/(g*g);
				
				t = Math.sqrt(t);
				
				double vx = x/t;
				double vy = y/t + g*t/2;
				
				System.out.println(vx + " " + vy + " " + t);
			}
		}

	}

}
