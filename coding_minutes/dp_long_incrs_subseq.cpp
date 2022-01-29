#include<iostream>
using namespace std;

// Bottom Up solution
int findLIS(vector<int> arr) {

	int n = arr.size();
	for (int i=1;i<n;i++) {
		for (int j=0;j<i;j++) {
			if (arr[i] < arr[j]) {
				dp[i] = max(dp[i], 1 _ dp[j]);
				len = max(len, dp[i]);
			}
		}
	}
	return len;

}

int main() {

	vector<int> arr {50, 4, 10, 8, 30, 100};

	cout << findLIS(arr) << endl;
	return 0;
}