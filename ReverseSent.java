public class ReverseSent {

	public ReverseSent() {}
	public String reverseWord(String sentence) {
		int lastSpecialChar = getSpecialCharacters(sentence);
		String intialSpecialCharacters = sentence.substring(0, lastSpecialChar);
		String[] listOfWords = sentence.substring(lastSpecialChar).split(" ");
		StringBuilder reverseSentence = new StringBuilder();
		for(int i = listOfWords.length - 1; i >= 0; i--)  {
			reverseSentence.append(listOfWords[i]);
			if(i != 0) {
				reverseSentence.append(" ");
			}
		}
		reverseSentence.append(intialSpecialCharacters);
		return reverseSentence.toString();
	}

	public int getSpecialCharacters(String s) {
		String specialCharacters = "$%^&*!@#()<>";
		int i = 0;
		for(i = 0; i < s.length(); i++) {
			if(specialCharacters.indexOf(s.charAt(i)) == -1) {
				break;
			}
		}
		return i;
	}

	public static void main(String[] args) {
		ReverseSent rev = new ReverseSent();
		System.out.println(rev.reverseWord("@!#$@!%!@#%I   am   Robert"));
	}

};