class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        int n = nums.size();
        int arr[51] = {0};
        int sum = nums[0]; 
        bool f = true;
        // unordered_map <int,int> mp;
        unordered_set <int> s;
        // s.
        // mp[nums[0]] = 1;
        for (int i = 1; i < n; i += 1) {
            if (f && nums[i] == 1 + nums[i - 1]) sum += nums[i];
            else break;
            // arr[nums[i]] = 1;
            // s.insert (nums[i]);

        }   

        while (true) {
            auto it = find(nums.begin(), nums.end(), sum);
            if (it == nums.end()) return sum;
            sum += 1;

        }


        return sum;
    }
};