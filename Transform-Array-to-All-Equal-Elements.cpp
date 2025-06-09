class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int ss = nums.size();
        vector<int> l = nums;
        int K = k;
        for (int i = 0 ; i < ss - 1 ; i += 1) {
            if (nums[i] != -1) {
                k -= 1;
                nums[i] *= -1 ,  nums[i + 1] *= -1;
            }
        }
        if (k >= 0 && nums[ss - 1] == -1) return true;
        k = K;
        nums = l;
        for (int i = 0 ; i < ss - 1 ; i += 1) {
            if (nums[i] != 1) {
                k -= 1;
                nums[i] *= -1 ,  nums[i + 1] *= -1;
            }
        }
        return (k >= 0 && nums[ss - 1] == 1);
    }
};