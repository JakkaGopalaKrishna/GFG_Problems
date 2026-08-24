
class Solution {
  private:
    int mod = 1e9+7;
  public:
    int prefixStrings(int n) {
        if(n<=2) return n;
        vector<vector<int>> dp(n+1,
        vector<int>(n+1,0));

        dp[n][n] = 1;

        for(int cnt0=n; cnt0>=0;cnt0--){
            for(int cnt1=n; cnt1>=0;cnt1--){
                if(cnt0>cnt1) break;

                if(cnt0 == n && cnt1 == n) continue;

                long long res=0;

                if(cnt0 < cnt1 && cnt0 < n)
                    res += dp[cnt0+1][cnt1];
                if(cnt1 < n)
                    res += dp[cnt0][cnt1+1];

                dp[cnt0][cnt1] = res%mod;
            }
        }

        return dp[0][0];
    }
};










//GFG POTD solution for 24 August