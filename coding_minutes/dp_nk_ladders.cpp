// to use DP -> optimal substructure and overlapping subproblems
// dp solution 1 :  top down approach : recursion + memoization
// dp solution 2 : bottom up :  fastter in execution

// ladder of steps N
// you can take utmost K steps


#include<iostream>
using namespace std;

int countWays(int n, int k) {
	if (n==0) {
		return 1;
	}

	if (n<0) {
		return 0;
	}

	int ans = 0;
	for (int jump = 1;jump<=k;jump++) {
		ans += countWays(n-jump, k);
	}
	return ans;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << countWays(n, k);
}