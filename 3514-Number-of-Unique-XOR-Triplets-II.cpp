class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set <int> mp;
        int n = nums.size();
        
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < n; j += 1) {
                mp.insert (nums[i] ^ nums[j]);
            }
        }   

        unordered_set <int> s;

        for (int i = 0; i < n; i += 1) {
            for (auto& j : mp) 
                s.insert (j ^ nums[i]);
        }
        return s.size();
    }
};