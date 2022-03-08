#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


bool compareBoxes(vector<int> b1, vector<int> b2) {
	return b1[2] < b2[2];
}

int boxStacking(vector<vector<int>> boxes) {

sort(boxes.begin()m bixes.end(), compareBoxes);

vector<int> dp(n+1, 0);

for (int i=0;i<n;i++) {
	dp[i] = boxes[i][2];
}



}

int main() {
	vector<vector<<int>> boxes = {

		{2, 1, 2},
		{3, 2, 3},
		{2, 2, 8},
		{2, 3, 4},
		{2, 2, 1},
		{4, 4, 5},
	};

	int height = boxStacking(boxes);

	return 0;
}