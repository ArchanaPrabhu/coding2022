#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;


int findMinJump(vector<int> v, int n, int index) {

	if (index >= (n - 1)) {
		return 0;
	}

	if (index == n-2) {
		return abs(v[index] - v[index+1]) + findMinJump(v, n, index + 1);
	}

	int first = abs(v[index] - v[index + 1]);
	int second = abs(v[index] - v[index + 2]);

	if (first < second) {
		return first + findMinJump(v, n, index + 1);
	} else {
		return second + findMinJump(v, n, index + 2);
	}
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

	cout<<findMinJump(v, n, 0)<< endl;
	return 0;
}