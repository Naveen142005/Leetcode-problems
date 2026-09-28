class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       
        vector <vector<int>> ans;
        int n = nums.size();
        
        for (int i = 0; i < n - 2; i += 1) {
            if (nums[i] > 0) break;
                   
            int tar = -1 * nums[i];

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                if (tar < nums[j] + nums[k]) {
                    k -= 1;
                }
                else if (tar > nums[j] + nums[k]) {
                    j += 1;
                }
                else {
                    ans.push_back ({nums[i], nums[j], nums[k]});
             
                    while (j + 1 < n && nums[j] == nums[j + 1]) j += 1;
                    while (k > 0 && nums[k] == nums[k - 1]) k -= 1;

                    j += 1;
                    k -= 1;
                }
            }
            while (i + 1 < n && nums[i] == nums[i + 1]) i += 1;
        }
        return ans;
    }
};

// -1, -1, 0, 1, 2, -4

//-4, -3, -2, -1, -1, 0, 0, 1, 2, 3, 4

