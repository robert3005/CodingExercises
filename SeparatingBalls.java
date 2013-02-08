import java.util.*;

public class SeparatingBalls {

	public int minOperations(int[] red, int[] green, int[] blue) {
		int[] res = new int[8];
		Arrays.fill(res, Integer.MAX_VALUE);
		res[0] = 0;
		for(int i = 0; i < red.length; i++) {
			int[] temp = new int[8];
			Arrays.fill(temp, Integer.MAX_VALUE);
			for(int j = 0; j < 8; j++) {
				if(res[j] != Integer.MAX_VALUE) {
					temp[j | 1] = Math.min(temp[j | 1], res[j] + green[i] + blue[i]);
					temp[j | 2] = Math.min(temp[j | 2], res[j] + red[i] + blue[i]);
					temp[j | 4] = Math.min(temp[j | 4], res[j] + red[i] + green[i]);
				}
				System.out.println("Iteration " + j);
				for(int t : temp) {
					System.out.print(t + " | ");
				}
				System.out.println();
				for(int b : res) {
					System.out.print(b + " | ");
				}
				System.out.println();
				System.out.println();
			}
			res = temp;
		}
		return res[7] == Integer.MAX_VALUE ? -1 : res[7];
	}

	public static void main(String[] args) {
		SeparatingBalls separator = new SeparatingBalls();
		int[] red   = {4, 6, 5, 7};
		int[] green = {7, 4, 6, 3};
		int[] blue  = {6, 5, 3, 8};
		//int[] red   = {1, 1, 1};
		//int[] green = {1, 1, 1};
		//int[] blue  = {1, 1, 1};
		System.out.println(separator.minOperations(red, green, blue));
	}
}