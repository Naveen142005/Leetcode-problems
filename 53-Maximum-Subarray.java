class Solution {
    public int maxSubArray(int[] nums) {
        int max = Integer.MIN_VALUE;
        int curr_sum = 0 ;
        for (int i = 0 ; i < nums.length ;i++){
            if (curr_sum < 0) curr_sum = 0;
            curr_sum += nums[i];
               max = curr_sum > max ? curr_sum : max;
        }
        return max;
    }
}