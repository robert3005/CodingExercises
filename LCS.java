import java.util.*;
import java.lang.Math;

public class LCS {

	public static int lcs(String a, String b) {
		int[][] result = new int[a.length()+1][b.length()+1];
		for( int i = 0; i <= a.length(); i++) {
			result[i][0] = 0;
		}
		for( int i = 0; i <= b.length(); i++) {
			result[0][i] = 0;
		}
		for(int i = 0; i < a.length(); i++) {
			for(int j = 0; j < b.length(); j++) {
				if(a.charAt(i) == b.charAt(j)) {
					result[i+1][j+1] = result[i][j] + 1;
				} else {
					result[i+1][j+1] = Math.max(result[i+1][j],result[i][j+1]);
				}
			}
		}
		return result[a.length()][b.length()];
	}

	public static void main(String[] args) {
		System.out.println(LCS.lcs(args[0], args[1]));
	}

}