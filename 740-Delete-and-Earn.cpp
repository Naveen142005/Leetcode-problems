class Solution {
public:
    int solve(unordered_map<int, int>& mp, vector<int>& dp, vector<int>& nums, int& ss, int idx, int tt) {
        if (idx == 0) return dp[idx];
        else if (dp[idx] != -1) return dp[idx];
        int e = nums[idx];
        bool f = true;
        int value = mp[nums[idx]] * nums[idx];
        while (idx - tt >= 0) {
            if (mp[e - 1] && f) {
                tt += 1;
                f = false;
            }
            if (idx - tt >= 0)
                dp[idx] = max(dp[idx],  value + solve(mp, dp, nums, ss, idx - tt, 1));
            tt += 1;
        }
        return dp[idx];
    }

    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size() - 1;
        if (!n) return nums[0];
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        vector<int> dp(n + 1, -1);

        for (auto& i : nums) 
            mp[i] += 1;

        int c = 1;
        int prev = 0;
        for (int i = 1; i <= n; i += 1) {
            if(nums[i-1]+1 != nums[i])
            if (nums[i - 1] != nums[i]) { 
                nums[c++] = nums[i];
                dp[i] = -1;
            }
        }

        dp[0] = mp[nums[0]] * nums[0];

        if (c - 1 >= 1) {
            int x = nums[1] * mp[nums[1]];
            dp[1] = mp[nums[1] - 1] ? x : x + dp[0];
        }

        if (c - 1 <= 0) return max(dp[0], dp[1]); 

        return max(solve(mp, dp, nums, c, c - 1, 1), solve(mp, dp, nums, c, c - 2, 1));
    }
};
