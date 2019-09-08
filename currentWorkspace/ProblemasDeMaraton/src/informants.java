import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

public class informants {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String initData = br.readLine();
		
		
		while (!initData.equals("0 0")) {
			String [] data = initData.split(" ");
			int ii = Integer.parseInt(data[0]);
			int a = Integer.parseInt(data[1]);
			HashMap<Integer, Informant> informants = new HashMap<>();
			for (int i = 1; i <= ii; i++) {
				informants.put(i, new Informant());
			}
			
			
			HashSet<Integer> notTrust = new HashSet<>();
			for (int i = 0; i < a; i++) {
				String info [] = br.readLine().split(" ");
				int informant = Integer.parseInt(info[0]);
				int accused = Integer.parseInt(info[1]);
				if (accused < 0) {
					informants.get(informant).noConf.add(-accused);
					notTrust.add(-accused);
				} else {
					informants.get(informant).conf.add(accused);
				}
			}
			
			while (!notTrust.isEmpty()) {
				for (int informant: notTrust) {
					informants.remove(informant);
				}
				HashSet<Integer> newsNoTrust = new HashSet<Integer>();
				for (int informant : informants.keySet()) {
					for (int informantTrust : informants.get(informant).conf) {
						if (notTrust.contains(informantTrust)) {
							newsNoTrust.add(informant);
							break;
						}
					}
				}
				notTrust = newsNoTrust;
			}
			
			bw.write(informants.size() + "\n");
			
			
			
			initData = br.readLine();
		}
		bw.close();

	}

}

class Informant {
	List<Integer> conf = new ArrayList<Integer>();
	List<Integer> noConf = new ArrayList<Integer>();
} 
