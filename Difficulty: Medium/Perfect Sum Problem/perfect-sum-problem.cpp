class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int m = target;
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(arr[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                } else if(arr[i-1]<=j){
                    int remaining_balls = j-arr[i-1];
                    dp[i][j] = dp[i-1][j] + dp[i-1][remaining_balls];
                }
            }
        }
        
        return dp[n][m];
    }
};