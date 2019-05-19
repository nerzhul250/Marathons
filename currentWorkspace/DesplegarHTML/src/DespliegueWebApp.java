import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class DespliegueWebApp {

	public static void main(String[] args) {
		System.out.println(":::Web Server Started:::");
		ServerSocket serverSocketWebService;
		try {
			serverSocketWebService = new ServerSocket(7000);
			while(true) {
				try {
					Socket cliente = serverSocketWebService.accept();
					HiloClientHandler hilo = new HiloClientHandler(cliente);
					hilo.start();	
				} catch (IOException e) {
					System.out.println("Exception in HiloDespliegueAppWeb");
				}
			}
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
		
	}

}
