class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector <int> arr1, arr2;

        // int i = 0, j = 1;
        
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        
        int n = nums.size();

        for (int x = 2; x < n; x += 1) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[x]);
            }
            else arr2.push_back(nums[x]);
        }
        
        for (auto i: arr2) arr1.push_back(i);

        return arr1;
    }
};