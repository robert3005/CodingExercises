#include <cmath>
#include <algorithm>
#include <iostream>

class NinjaTurtles {

	public:
		int countOpponents(int P, int K) {
			int N = 1;
			// Increase N until the value of the formula is >= P.
			while (3*(N/K) + N/3 < P) {
				N++;
			}
			return 3*(N/K) + N/3 == P ? N : -1;
		}
};

int main(int argc, char* argv[]) {
	return 0;
}