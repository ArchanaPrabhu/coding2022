#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

int memo[N];

int findMinJump(vector<int> v, int n, int index) {

	if (index >= (n - 1)) {
		return 0;
	}

	if (index == n-2) {
		return abs(v[index] - v[index+1]) + findMinJump(v, n, index + 1);
	}

	int first = abs(v[index] - v[index + 1]);
	int second = abs(v[index] - v[index + 2]);

	return min(first + findMinJump(v, n, index + 1), second + findMinJump(v, n, index + 2));
	
}

int findMinJump2(vector<int> v, int n) {
	vector<int> dp(n, 0);
	dp[0] = 0;
	dp[1] = dp[0] + abs(v[0] - v[1]);


	for (int i = 2;i<n;i++) {
		dp[i] = min(dp[i-1] + abs(h[i-1] - [i]), dp[i-2] + abs(h[i-2] - h[i]));
	}
	return dp[n - 1];
}

int dp(int n, vector<int> h) {
	if (n == 0) return 0;
	int &ans = memo[n];

	if (ans != -1) return ans;
	ans = dp(n - 1) + abs(h[n - 1] - h[n]);

	if (n - 2 >= 0) ans = min(ans, dp(n - 2) + abs(h[n - 2] - h[n]));

	return ans;
}


int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i=0;i<n;i++) {
		int input;
		cin >> input;
		v[i] = input;
	}

	cout<<findMinJump(v, n, 0)<< endl; // myy solution - right!!

	memset(memo, -1, sizeof(memo));
	cout << dp(n, v); // botton up approach

	return 0;
}
/**
6
30 10 60 10 60 50
60
*/