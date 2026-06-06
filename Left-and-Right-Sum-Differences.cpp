1class Solution {
2public:
3    vector<int> leftRightDifference(vector<int>& nums) {
4        int n = nums.size();
5        vector <int> ans (n , 0);   
6
7        for (int i = 1; i < n; i += 1)
8            ans[i] += ans[i - 1] + nums[i - 1];
9        
10        for (int i = n - 2; i >= 0; i -= 1) {
11            ans[i] = abs (ans[i] - nums[i + 1]);
12            nums[i] += nums[i + 1];
13        }
14
15        return ans;
16    }
17};