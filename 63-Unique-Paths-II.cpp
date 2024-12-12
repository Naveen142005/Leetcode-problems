class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        ios_base::sync_with_stdio(false);
        int m = arr.size();
        int n = arr[0].size();
        if (arr[0][0] || arr[m - 1][n - 1])
            return 0;
        vector<vector<long>> dp(m, vector<long>(n));
        for (int i = 0; i < m; i += 1) {
            for (int j = 0; j < n; j += 1) {
                if (!i || !j) {
                    if (arr[i][j])
                        dp[i][j] = 0;
                    else {
                        if (j > 0 && !dp[i][j - 1])
                            dp[i][j] = 0;
                        else if (i > 0 && !dp[i - 1][j])
                            dp[i][j] = 0;
                        else
                            dp[i][j] = 1;
                    }
                } else {
                    if (arr[i - 1][j] && arr[i][j - 1])
                        dp[i][j] = 0;
                    else if (arr[i][j - 1]) {
                        dp[i][j] = dp[i - 1][j];
                    } else if (arr[i - 1][j]) {
                        dp[i][j] = dp[i][j - 1];
                    } else
                        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};