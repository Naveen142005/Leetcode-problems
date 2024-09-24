class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        int p = 1 , n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        for (int i = 1 ; i < n ; i++) 
            p *= nums[i - 1] , ans[i] = p;
        p = 1;
        for (int i = n - 1 ; i >= 0 ; i--) 
            ans[i] *= p , p *= nums[i];
        return ans;
    }
};