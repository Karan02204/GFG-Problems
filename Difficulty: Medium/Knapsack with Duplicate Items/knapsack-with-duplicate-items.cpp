// User function Template for C++

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n= wt.size();
        int m = capacity;
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(wt[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                } else if(wt[i-1] <=j ){
                    int remaining_balls = j-wt[i-1];
                    dp[i][j] = max(val[i-1] + dp[i][remaining_balls] , dp[i-1][j]);
                }
            }
        }
        
        return dp[n][m];
    }
};