class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // add 1 before and after nums
        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);
        // dp[i][j] represents
        // maximum if we burst all nums[left]...nums[right], inclusive
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        // do not include the first one and the last one
        // since they are both fake balloons added by ourselves and we can not burst them
        for (int left = nums.size() - 2; left >= 1; left--) {
            for (int right = left; right <= nums.size() - 2; right++) {
                // find the last burst one in nums[left]...nums[right]
                for (int i = left; i <= right; i++) {
                    // nums[i] is the last burst one
                    int gain = nums[left - 1] * nums[i] * nums[right + 1];
                    // recursively call left side and right side
                    int remaining = dp[left][i - 1] + dp[i + 1][right];
                    // update
                    dp[left][right] = max(remaining + gain, dp[left][right]);
                }
            }
        }
        // burst newNums[1]...newNums[n-2], excluding the first one and the last one
        return dp[1][nums.size() - 2];
    }
};