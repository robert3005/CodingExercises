import java.util.*;
import java.lang.Math;

public class Knapsack {

	/* Extremely useful for debugging dynamic programming problems */
	public static void printArr(int[][] arr) {
		for(int i = 0; i < arr.length; i++){
			for(int j = 0; j< arr[0].length; j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
		System.out.println();
	}

	public static int maximumLoot(int[] values, int[] weights, int capacity) {
		int numItems = values.length;
		int[][] maxBenefit = new int[numItems+1][capacity+1];
		for(int i = 0; i <= numItems; i++) {
			maxBenefit[i][0] = 0;
		}
		for(int i = 0; i <= capacity; i++) {
			maxBenefit[0][i] = 0;
		}
		for(int i = 0; i < numItems; i++) {
			for(int j = 0; j <= capacity; j++) {
				if(weights[i] <= j) {
					maxBenefit[i+1][j] = Math.max(values[i] + maxBenefit[i][j-weights[i]], maxBenefit[i][j]);
				} else {
					maxBenefit[i+1][j] = maxBenefit[i][j];
				}
			}
		}

		return maxBenefit[numItems][capacity];
	}

	public static void main(String[] args) {

		System.out.println(Knapsack.maximumLoot(new int[] { 3, 4, 5, 6 }, new int[] { 2, 3, 4, 5 }, 5));

	}
}