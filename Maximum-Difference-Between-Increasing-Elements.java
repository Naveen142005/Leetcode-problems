class Solution {
    public int maximumDifference(int[] nums) {
        int mx = nums[0],
        len = nums.length,
        ans = -1;
        
        for (int i = 1 ; i < len ; i += 1) {
            if (nums[i] > mx) 
                ans = Math.max (ans , nums[i] - mx);
            mx = Math.min (mx , nums[i]);
        }
        return ans;
    }
}