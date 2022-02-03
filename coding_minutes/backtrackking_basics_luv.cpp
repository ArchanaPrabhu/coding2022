#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets;

void generate(vector<int> &subset, int i, vector<int> &nums) {
	// either include i or do not 

	// base condition is wen the numbers exhaust
	if (i == nums.size()) { 
		subsets.push_back(subset);
	}

	// do not include
	generate(subset, i+1, nums);

	subset.push_back(nums[i]);

	// include
	generate(subset, i+1, nums);

	// backtrack and remove the added element
	subset.pop_back(nums[i]);

	// print subsets function
}
