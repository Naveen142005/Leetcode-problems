class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int ss = nums.size();
        sort(nums.begin(),nums.end());
        long long res = 0;
        for (int i = 0 ; i < ss ; i += 1) {
            int low = 
                lower_bound (nums.begin() + (i + 1) , nums.end() , lower - nums[i]) - nums.begin();
            int upp =
                upper_bound (nums.begin() + (i + 1) , nums.end() , upper - nums[i]) - nums.begin();
            
            res += abs(low- upp );
        }
        return res;
    }
};