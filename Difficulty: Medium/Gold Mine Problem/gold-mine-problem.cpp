class Solution {
  public:
    bool isvalid(int i, int j, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n) return false;
        return true;
    }
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>>dp = mat;
        
        for(int j=n-2; j>=0; j--){
            for(int i=0; i<m; i++){
                int right_up = (i-1 >= 0) ? dp[i-1][j+1] : 0;
                int right_down = (i+1 < m) ? dp[i+1][j+1] : 0;
                dp[i][j] = dp[i][j] + max({dp[i][j+1], right_up, right_down});
            }
        }
        int res = 0;
        for(int i=0; i<m; i++){
            res = max(res, dp[i][0]);
        }
        return res;
        
    }
};
//GFG POTD solution for 12 July