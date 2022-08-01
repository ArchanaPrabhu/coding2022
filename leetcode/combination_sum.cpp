class Solution {
public:
    void findCombination(int index, vector<int>& arr, int target, vector<vector<int>>& ans, vector<int>& arrEntry)     {
        if (index >= arr.size()) {
            if (target == 0) {
                ans.push_back(arrEntry);
            }
            return;
        }
        
        if (arr[index] <= target) {
            arrEntry.push_back(arr[index]);
            findCombination(index, arr, target - arr[index], ans, arrEntry);
            arrEntry.pop_back();
        }
        
        findCombination(index + 1, arr, target, ans, arrEntry);
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> arrEntry;
        findCombination(0, arr, target, ans, arrEntry);
        return ans;
    }
};
