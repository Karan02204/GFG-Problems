// User function Template for C++

class Solution {
  public:
    int isTriangular(int n) {
        vector<int> dp(n+1,-1);
        // code here
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            dp[i] = dp[i-1] + i;
            if(dp[i] == n) return 1;
        }
        
        return 0;
    }
};