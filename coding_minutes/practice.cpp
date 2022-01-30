#include<iostream>
#include<vector>
using namespace std;


void backtrack(vector<int> h, vector<int> dp, int n, int k, int index) {
	cout << index + 1<< " -- " << endl;
	for (int i = 0; i < n;i++) {
		for (int j=1; j<= k && (i-j)>=0; j++) {
			if (dp[i] == dp[i-j] + abs(h[i] - h[j])) {
				backtrack(h, dp, n, k, i-j);
				return;
			}
		
		}
	}	
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> h(n, 0);
	for (int i = 0; i<n;i++) {
		cin >> h[i];
	}

	vector<int> dp(n, 0);
	dp[0] = 0;
	dp[1] = dp[0] + abs(h[1] - h[0]);
	for (int i = 0; i < n;i++) {
		for (int j=1; j<= k && (i-j)>=0; j++) {
			dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[j]));
		}
	}


	cout << dp[n-1];

	backtrack(h, dp, n, k, n-1);
}

