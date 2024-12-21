class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n , INT_MAX);
        dp[n - 1] = 0;
        for (int i = n - 2 ; i >= 0 ; i -= 1) {
            int m = nums[i];
            
            while (m > 0) {
                if (n - 1 <= m + i) {
                    dp[i] = 1;
                }
                else if (dp[m + i] != INT_MAX) dp[i] = min (dp[i], dp[m + i] + 1);
                m -= 1;
            }
        }
        return dp[0];
    }
};