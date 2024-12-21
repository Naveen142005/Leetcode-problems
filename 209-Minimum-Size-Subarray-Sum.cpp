class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int p = 0;
        int sum = 0;
        int ans = 0;
        int mx = INT_MAX;
        for (int i = 0 ; i < nums.size() ; i += 1) {
            if (sum >= target) mx = min (ans , mx);
            sum += nums[i];
            ans += 1;
            if (sum >= target) mx = min (ans , mx);
            while (sum >= target) {
                if (sum >= target) mx = min (ans , mx);
                sum -= nums[p];
                ans -= 1;
                if (sum >= target) mx = min (ans , mx);
                p += 1;
            }
        }
        return mx != INT_MAX ? mx : 0;

    }
};