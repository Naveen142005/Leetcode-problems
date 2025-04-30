class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int ss = nums.size();
        int st = 0;
        int i = 0;
        long long cnt = 0;
        int mx = *max_element(nums.begin(), nums.end());
        int mx_cnt = 0;
        while (i < ss) {
            if (nums[i] == mx) mx_cnt += 1;
            while (mx_cnt >= k) {
                cnt += (ss - i);
                if (nums[st] == mx) mx_cnt -= 1;
                st += 1;
            }
            i += 1;
        }
        return cnt;
    }
};