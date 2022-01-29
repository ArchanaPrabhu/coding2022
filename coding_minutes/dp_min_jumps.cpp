#include<iostream>
#include<vector>
using namespace std;


// top down based DP approach
int min_jumps(vector<int> arr, int n, vector<int> dp, int i) {
	if (i >= n) {
		cout << "index : " << i << " return INT_MAX" << endl;
		return INT_MAX;
	}

	if (i == n -1) {
		cout << "index : " << i << " return 0" << endl;
		return 0;
	}

	if (dp[i] != 0) {
		cout << "index : " << i << " return mem dp[i] = " << dp[i] << endl;
		return dp[i];
	}


	int steps = INT_MAX;
	int max_jump = arr[i];
	for (int j=1;j<=max_jump;j++) {
		int sub_steps = min_jumps(arr, n, dp, i + j);

		if (sub_steps != INT_MAX) {
			steps = min(steps, sub_steps + 1);
		}
	cout << "max_jump " << max_jump << " ,j = " << j << endl;
	}

	cout << "index : " << i << " return dp[i] " << dp[i] << endl;
	return dp[i] = steps;
}

int main() {	
	vector<int> arr = {3, 4, 2, 1, 2, 3, 7, 1, 1, 3};
	int n = arr.size();

	vector<int> dp(n, 0);
	cout << min_jumps(arr, n, dp, 0);
	return 0;

}