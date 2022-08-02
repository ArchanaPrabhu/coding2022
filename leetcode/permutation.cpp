class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> ansEntry;
        int freq[nums.size()];
        memset(freq, 0, sizeof(freq));
        for (int i=0;i<nums.size();i++) {
            freq[i] = 0;
        }
        startPermuting(nums, ans, ansEntry, freq);
        return ans;
        
    }
    
    void startPermuting(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ansEntry,int freq[]) {
        if (ansEntry.size() == nums.size()) {
            ans.push_back(ansEntry);
            return;
        }
        
        for (int i=0;i<nums.size();i++) {
            if (!freq[i]) {
                ansEntry.push_back(nums[i]);
                freq[i] = 1;
                startPermuting(nums, ans, ansEntry, freq);
                freq[i] = 0;
                ansEntry.pop_back();
            }
        }
        
    }
};