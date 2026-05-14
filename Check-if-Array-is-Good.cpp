1class Solution {
2public:
3    bool isGood(vector<int>& nums) {
4        int n = nums.size();
5        vector <int> mp (201, 0);
6
7        for (auto& i: nums)
8            mp[i] += 1;
9        
10        for (int i = 1; i < n - 1; i += 1) {
11             if (mp[i] != 1) return false;
12        }
13        if (mp[n - 1] != 2) return false;
14
15        return true;
16    }
17};