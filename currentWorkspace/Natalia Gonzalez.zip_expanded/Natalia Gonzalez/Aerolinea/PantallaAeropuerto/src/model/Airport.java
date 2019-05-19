package model;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Random;

public class Airport {
	
	private ArrayList<Flight> flights;
	
	private int numFlights;
	
	public final static String PATH_AIRLINES = "./data/airlines.txt";
	public final static String PATH_CITIES = "./data/cities.txt";
	public final static String PATH_GATES =  "./data/boardingGates.txt";
	
	//Constructor
	public Airport() {
		flights = new ArrayList<Flight>();
	}
	
	
	
	
	
	
	//retorna la ubicacion en la lista donde esta el codigo, si es -1, no se encontro
	public int searchForCode(String code) {
		int n = -1;
		organizeForCode();
		boolean found = false;
		int start = 0;
		int finish = flights.size() -1;
		int medium = (start + finish)/2;
		
		while(start <= finish && !found) {
			medium = (start + finish)/2;
			boolean salir = false;
			
			for (int i = 0; i < code.length() && !salir; i++) {
				int fC = (int)code.charAt(i);
				int f = (int)flights.get(medium).getCode().charAt(i);
				
				if(flights.get(medium).getCode().equals(code)) {
					n = medium;
					found = true;
					salir = true;
				}else if(f > fC) {
					finish = medium -1;
					salir = true;
				}else {
					start = medium +1;
					salir = true;
				}
			}
		}
		return n;
	}
	
	public void organizeForCode() {
		for (int i = 0; i < flights.size(); i++) {
			for (int j = ; j < flights.size(); j++) {
				
			}
		}
	}
	
	public void organizeDataAndTime() {
		for (int i = 0; i < flights.size(); i++) {
			for (int j = ; j < flights.size(); j++) {
				
			}
		}
	}
	
	public void setNumFlights(String n) {
		int num = 0;
		try {
			num = Integer.parseInt(n);
		}catch(Exception e) {
			
		}
		numFlights = num;
	}
	
	public void addFlight(int time, Calendar calendar, String airline, String code, String destination, String boardingGate) {
		flights.add(new Flight(time, calendar, airline, code, destination, boardingGate));
	}
	
	public void generateList() {
		flights.clear();
		ArrayList<String> cities = loadList(PATH_CITIES);
		ArrayList<String> airlines = loadList(PATH_AIRLINES);
		ArrayList<String> gates = loadList(PATH_GATES);
		Random rmd = new Random();
		String city = "";
		String airline = "";
		String gate = "";
		Calendar day;
		//Calendar hour;
		int time = 0;
		String code = "";
		for (int i = 0; i < numFlights; i++) {
			city = cities.get(rmd.nextInt(cities.size()));
			airline = airlines.get(rmd.nextInt(airlines.size()));
			gate = gates.get(rmd.nextInt(gates.size()));
			//hour = hour.getInstance();
			//hour.set
			day = Calendar.getInstance();
		    day.set (2019, rmd.nextInt(12)+1, rmd.nextInt(30)+1);
		    time =  rmd.nextInt(24*60)+1;
		    code = airline.charAt(0)+""+(i+1);    
			addFlight(time, day, airline, code, city, gate);
		}
	}
	
	public ArrayList<String> loadList(String path) {
		ArrayList<String> list = new ArrayList<String>();
		
		try {
			BufferedReader bf = new BufferedReader(new FileReader(path));
			String line = bf.readLine();
			while(line != null) {
				list.add(line);
				line = bf.readLine();
				}
				line = bf.readLine();
			bf.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		return list;
	}
	
	public ArrayList<Flight> getFlights() {
		return flights;
	}
}
