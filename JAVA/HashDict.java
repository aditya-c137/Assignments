import java.util.*;

public class HashDict {

	public static void main(String[] args) {
		int checker;
		Hashtable<String, LinkedList<String>> hashhhh  = new Hashtable<String, LinkedList<String>>();
		int alpha[] = new int[26];
		for (int num = 0; num<26; num++)
		{
			alpha[num] = 0;
		}
		Scanner userIn = new Scanner(System.in);
		while(true){
			String finder = userIn.nextLine();
			char hui = finder.charAt(0);
			int hoola = (int)hui;
			String ponga;
			if (hoola >= 97){	
				checker = hoola - 97;
				ponga = String.valueOf((char)hoola);
			}
			else {
				checker = hoola - 65;
				ponga = String.valueOf((char)(hoola + 32));
			}
			if (alpha[checker] == 0){
				alpha[checker] = 1;
				LinkedList<String> alphaStore = new LinkedList<String>();
				alphaStore.add(finder);
				hashhhh.put(ponga,alphaStore);
				System.out.println(hashhhh);
			}
			else
			{
				LinkedList<String> oof = new LinkedList<String>();
				oof = hashhhh.get(ponga);
				oof.add(finder);
				hashhhh.put(ponga,oof);
				System.out.println(hashhhh);
			}
		}
	}
	
}
