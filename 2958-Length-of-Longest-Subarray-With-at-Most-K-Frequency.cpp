class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        int n = nums.size();
        int st = 0;
        int mx = 1;

        for (int right = 0; right < n; right += 1) {
            
            mp[nums[right]] += 1;

            while (mp[nums[right]] > k && st < n) {
                mp[nums[st]] -= 1;
                st += 1;
            }

            mx = max (right - st + 1, mx);

        }
        return mx;
    }
};