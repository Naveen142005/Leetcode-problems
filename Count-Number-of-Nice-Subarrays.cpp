class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int prev = 0 , cnt = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for (auto& i : nums) {
            prev = prev + ((i & 1) ? 1 : 0);
            if (mp.find(prev - k) != mp.end())
                cnt += mp [prev - k];
            mp[prev] += 1;
        }
        return cnt;
    }
};