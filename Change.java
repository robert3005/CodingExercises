import java.util.*;
import java.lang.Math;

public class Change {

	public int minChange(int n, int[] denominations) {
		int[] numCoins = new int[n+1];
		for(int i = 0; i <= n; i++) {
			numCoins[i] = 0;
		}
	    for (int i = 1; i <= n; i++) { // cycling up to the wanted value
	        int min = Integer.MAX_VALUE; //assigning current minimum number of coints
	        for (int value : denominations) {//cycling through possible values
	            if (value <= i) {
	                if (1 + numCoins[i - value] < min) { //if current value is less than min
	                    min = 1 + numCoins[i - value];//assign it
	                }
	            }
	        }
	        numCoins[i] = min; //assign min value to array of coins
	   	}
		return numCoins[n];
	}

	public int countChanges(int n, int lastDenom, int[] denominations) {
		if(n == 0) {
			return 1;
		}
		if (n < 0) {
			return 0;
		}
		if (n >= 1 && lastDenom < 0) {
			return 0;
		}

		return countChanges(n, lastDenom - 1, denominations) + countChanges(n - denominations[lastDenom], lastDenom, denominations);
	}

	public static void main(String[] args) {

		int[] denoms = new int[] { 1, 2, 5, 10, 20, 50 };
		Change chng = new Change();

		System.out.println(chng.minChange(79,denoms));
		System.out.println(chng.countChanges(79,5,denoms));
	}
}