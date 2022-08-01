class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        vector<int> prev(n);
        int maxSide = 0;
        for(int i=0;i<m;i++){
            vector<int> cur(n);
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1'){
                    int a = i>0 ? prev[j] : 0;
                    int b = j>0 ? cur[j-1] : 0;
                    int c = (i>0 && j>0) ? prev[j-1] : 0;
                    cur[j] = 1 + min({a,b,c});
                    maxSide = max(maxSide, cur[j]);
                }
            }
            prev = cur;
        }
        
        return maxSide * maxSide;
    }
};
