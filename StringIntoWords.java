import java.util.*;

public class StringIntoWords {

	private List<String> dict;

	public StringIntoWords(List<String> dict) {
		this.dict = dict;
	}

	boolean stringSegmentation(String s) {
		boolean[] words = new boolean[s.length()];
		words[0] = isValidWord(s.substring(0,1));
		for( int i = 1; i < s.length(); i++) {
			for (int j = 0; j < i; j++) {
				words[i] = words[j] && isValidWord(s.substring(j+1,i+1));
				if(words[i]) {
					break;
				}
			}
			words[i] = words[i] || isValidWord(s.substring(0,i));
		}

		return words[s.length()-1];

	}

	boolean isValidWord(String s) {
		return this.dict.contains(s);
	}

	public static void main(String[] args) {
		String input = args[0];
		List<String> dict = new ArrayList<String>() {{
			add("I");
			add("am");
			add("not");
			add("here");
		}};
		StringIntoWords sWords = new StringIntoWords(dict);
		System.out.println(sWords.stringSegmentation(input));
	}

}