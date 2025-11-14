class Solution {
  public:
    double waterOverflow(int K, int R, int C) {
        // code here
        vector<vector<double>> dp(500, vector<double>(500,0.0));
        dp[0][0] = K;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c <= r; ++c) {
                if (dp[r][c] > 1.0) {
                    double excess = dp[r][c] - 1.0;
                    if (r + 1 < 100) {
                        dp[r + 1][c] += excess / 2.0;
                        dp[r + 1][c + 1] += excess / 2.0;
                    }
                }
            }
        }
        return dp[R -1][C -1] >= 1.0 ? 1.0 : dp[R -1][C -1];
    }
};