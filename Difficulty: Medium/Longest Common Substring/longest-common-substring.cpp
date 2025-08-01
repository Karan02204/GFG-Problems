class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.length();
        int m = s2.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int answer = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    answer = max(answer , dp[i][j]);
                } else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return answer;
        
    }
};