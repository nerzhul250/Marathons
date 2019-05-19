

/**
 * Hilo que se encarga de darle una respuesta en formato HTTMl a un cliente que accede
 * a traves de localhost:puerto para consultar la pagina del login , ingresar su cedula 
 * y realizar la busqueda de sus apuestas
 */

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.StringTokenizer;


public class HiloClientHandler extends Thread{
	
	private Socket socket;
	public HiloClientHandler(Socket socket) {
		
		this.socket = socket;
	}
	
	public void run() {

		//le quite el while true
			handleRequest(this.socket);
		
		
	}

	private void handleRequest(Socket socket2) {
		try {
			BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			String headerLine = in.readLine();
			// A tokenizer is a process that splits text into a series of tokens
			StringTokenizer tokenizer =  new StringTokenizer(headerLine);
			//The nextToken method will return the next available token
			String httpMethod = tokenizer.nextToken();
			// The next code sequence handles the GET method. A message is displayed on the
			// server side to indicate that a GET method is being processed
			if(httpMethod.equals("GET"))
			{
				System.out.println("Get method processed");
				String httpQueryString = tokenizer.nextToken();
				System.out.println(httpQueryString);
				if(httpQueryString.equals("/"))
				{
					StringBuilder responseBuffer =  new StringBuilder();
					String str="";
					BufferedReader buf = new BufferedReader(new FileReader("C:\\Users\\asus\\Documents\\GitHub\\Marathons\\currentWorkspace\\DesplegarHTML\\src\\icesiMain.html"));			
					while ((str = buf.readLine()) != null) {
						responseBuffer.append(str);
				    }
					sendResponse(socket, 200, responseBuffer.toString());		
				    buf.close();
				}else {
					StringBuilder responseBuffer =  new StringBuilder();
					String str="";
					httpQueryString=httpQueryString.substring(1);
					BufferedReader buf = new BufferedReader(new FileReader("C:\\Users\\asus\\Documents\\GitHub\\Marathons\\currentWorkspace\\DesplegarHTML\\src\\"+httpQueryString));			
					while ((str = buf.readLine()) != null) {
						responseBuffer.append(str);
				    }
					sendResponse(socket, 200, responseBuffer.toString());		
				    buf.close();
				}
				System.out.println("The HTTP method is not recognized");
				sendResponse(socket, 405, "Method Not Allowed");
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}	
		
	}
	private void agregarlista(String[] lista , StringBuilder responseBuffer, String cedula) {
		for (int i = 0; i < lista.length; i++) {
			System.out.println("CHEQUEO LISTA :" + lista[i]);
			if(lista[i].split(",")[0].compareToIgnoreCase(cedula)==0) {
				responseBuffer.append("<tr>");
				responseBuffer.append("<td>"+lista[i].split(",")[0]+"</td>");
				responseBuffer.append("<td>"+lista[i].split(",")[1]+"</td>");
				responseBuffer.append("<td>"+lista[i].split(",")[2]+"</td>");
				responseBuffer.append("<td>"+lista[i].split(",")[3]+"</td>");
				responseBuffer.append("<tr>");
			}
			
		}
		
	}

	public void sendResponse(Socket socket, int statusCode, String responseString)
	{
		String statusLine;
		String serverHeader = "Server: WebServer\r\n";
		String contentTypeHeader = "Content-Type: text/html\r\n";
		
		try {
			DataOutputStream out =  new DataOutputStream(socket.getOutputStream());
			if (statusCode == 200) 
			{
				statusLine = "HTTP/1.0 200 OK" + "\r\n";
				String contentLengthHeader = "Content-Length: "
				+ responseString.length() + "\r\n";
				out.writeBytes(statusLine);
				out.writeBytes(serverHeader);
				out.writeBytes(contentTypeHeader);
				out.writeBytes(contentLengthHeader);
				out.writeBytes("\r\n");
				out.writeBytes(responseString);
				} 
			else if (statusCode == 405) 
			{
				statusLine = "HTTP/1.0 405 Method Not Allowed" + "\r\n";
				out.writeBytes(statusLine);
				out.writeBytes("\r\n");
			} 
			else 
			{
				statusLine = "HTTP/1.0 404 Not Found" + "\r\n";
				out.writeBytes(statusLine);
				out.writeBytes("\r\n");
			}
			out.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
