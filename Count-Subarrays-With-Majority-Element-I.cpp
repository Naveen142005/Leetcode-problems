1class Solution {
2public:
3    int countMajoritySubarrays(vector<int>& nums, int target) {
4        int sz = nums.size();
5        int sum = 0;
6        for (int i = 0; i < sz; i += 1) {
7            int cnt = 0, no = 0;
8            for (int j = i; j < sz; j += 1) {
9                no += 1;
10                if (nums[j] == target) cnt += 1;
11                if (cnt > no / 2) sum += 1;
12            }
13
14            
15            
16        }
17
18        return sum;
19    }
20    
21};