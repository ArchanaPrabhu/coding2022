#include<iostream>
#include<vector>

void go(int i, int j) {
	if (i<0 || i>=n) {
		return 0;
	}

	if (dp[i][j] == dp[i-1][j] + max(dp[i-1][1], dp[i-1][2])) {
		cout << " 0 " << endl;
		go(i-1, 1);
		go(i-1, 2);
	} else if(dp[i][j] == dp[i-1][j] + max(dp[i-1][0], dp[i-1][2])) {
		cout << " 1 " << endl;
		go(i-1, 1);
		go(i-1, 2);
	} else if(dp[i][j] == dp[i-1][j] + max(dp[i-1][0], dp[i-1][1])) {
		cout << " 2 " << endl;
		go(i-1, 1);
		go(i-1, 2);
	}
		
}

int findMaxGains(vector<int> a, vector<int> b, vector<int> c, int n) {

	vector<vector<int>> dp[n][3];

	dp[0][2] = a[0];
	dp[1][2] = b[0];
	dp[2][2] = c[0];
	for (int i=0;i<n;i++) {
		for (int j=0;j<3;j++) {
			if (j==0) {
				dp[i][j] = dp[i-1][j] + max(dp[i-1][1], dp[i-1][2]);
			} else if(j==1) {
				dp[i][j] = dp[i-1][j] + max(dp[i-1][0], dp[i-1][2]);
			} else if(j==2) {
				dp[i][j] = dp[i-1][j] + max(dp[i-1][0], dp[i-1][1]);
			} 
		}
	}
	return dp[n][n];
}


int main() {
	int n;
	cin >> n;

	vector<int> a(n, 0);
	vector<int> b(n, 0);
	vector<int> c(n, 0);

	for (int i=0;i<n;i++) {
		cin >> a[i];
		cin >> b[i];
		cin >> c[i];
	}

	cout << findMaxGains(a, b, c, n) << endl;

}
/**
3
10 40 70
20 50 80
30 60 90
**/