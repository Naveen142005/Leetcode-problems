class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0  ; i < n - 2 ; i += 1) {
            if ((double)(nums[i] + nums[i + 2])== nums [i + 1] / 2.0 ) cnt += 1;
        }
        return cnt;
    }
};