class TheSquareRootDilemma {

	public:
		int countPairs(int N, int M) {
			int count = 0;
			for(int a = 1; a <= N; a++) {
				int s = 1;
				for(int x = 2; x <= a/x; x++) {
					if(a % (x*x) == 0) {
						s = x*x;
					}
				}
				int r = a / s;
				for(int y = 1; y*y*r <= M; y++) {
					count++;
				}
			}
			return count;
		}
};

int main(int argc, char const *argv[]) {
	return 0;
}