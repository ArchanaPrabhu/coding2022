// to use DP -> optimal substructure and overlapping subproblems
// dp solution 1 :  top down approach : recursion + memoization
// dp solution 2 : bottom up :  fastter in execution

// ladder of steps N
// you can take utmost K steps


#include<iostream>
using namespace std;

// O(k^n)
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

	int dp[1000] = {0};
	cout << countWaysTopDown(n, k, dp);
}

// O(n*k)
// n unique states
int countWaysTopDown(int n, int k, int * dp) {

	if (n == 0) {
		return 1;
	}

	if (n < 0) {
		return 0;
	}

	if (dp[n] != 0) {
		return dp[n];
	}

	for (int jump = 1;jump <=k;jump++) {
		ans += countWaysTopDown(n-jump, k, dp);
	}

	return dp[n] = ans;
}

// Bottom up approach - iterative - O(n*k)
int countWaysBottomUp(int n, int k) {
	vector<int> dp(n+1, 0);
	dp[0] = 1;
	for (int i=1;i<=n;i++) {
		for (int jump = 1;jump<=k;jump++) {
			if (i-jump >=0) {
				dp[i] +=dp[i-jump];
			}
		}
	}
	return dp[n];
}

// Bottom up approach - iterative - O(n + k)
int countWaysBottomUp(int n, int k) {
	vector<int> dp(n+1, 0);
	dp[0] = dp[1] = 1;
	for (int i=2;i<=k;i++) {
		dp[i] = 2*dp[i-1];
	}

	for (int i = k+1; i<=n;i++) {
		dp[i] = 2*dp[i-1] - dp[i-k-1];
	}
	return dp[n];
}





