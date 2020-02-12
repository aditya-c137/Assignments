import java.util.*;

public class HashDict {

	public static void main(String[] args) {
		int checker;
		//System.out.println(args[0]);
		Hashtable<String, LinkedList<String>> hashhhh  = new Hashtable<String, LinkedList<String>>();
		int alpha[] = new int[26];
		for (int num = 0; num<26; num++)
		{
			alpha[num] = 0;
		}
		//Scanner userIn = new Scanner(System.in);
		//while(true){
		int input;
		input = Integer.parseInt(args[0]);
		for (int i = 1; i <= input; i++){
			//String finder = userIn.nextLine();
			//char hui = finder.charAt(0);
			char hui = args[i].charAt(0);
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
				alphaStore.add(args[i]);
				hashhhh.put(ponga,alphaStore);
			//	System.out.println(hashhhh);
			}
			else
			{
				LinkedList<String> oof = new LinkedList<String>();
				oof = hashhhh.get(ponga);
				oof.add(args[i]);
				hashhhh.put(ponga,oof);
			//	System.out.println(hashhhh);
			}
		}
		System.out.println(hashhhh);
		//--------------------------------------------Search Block----------------------------------------------
		System.out.print("Search:");
		Scanner UserIn = new Scanner(System.in);
		String finder = UserIn.nextLine();
		char b = finder.charAt(0);
		String bucket = Character.toString(b);
		LinkedList<String> bucketin = new LinkedList<String>();
		bucketin = hashhhh.get(bucket);
		System.out.println(bucketin);
		int length = finder.length();
		int size = bucketin.size();
		System.out.println("Did you mean?");
		for(int i = 0; i<size; i++){
			 String print = bucketin.get(i);
			 for(int j = 0; j<length; j++){
				char printer = print.charAt(j);
				if(printer != finder.charAt(j)){
					break;
				}
				else if(j == length -1){
					System.out.println(print);
				}
			 }
		}
	}
}
