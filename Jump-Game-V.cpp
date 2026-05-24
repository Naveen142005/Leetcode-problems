1class Solution {
2public:
3    int n;
4    int dp[1001] = {0};
5    int solve (vector<int>& nums, int d, int idx) {
6
7        int x = 1;
8        bool f1 = true;
9        bool f2 = true;
10        int res = 1;
11
12        if (dp[idx]) return dp[idx];
13        
14        while (true) {
15            int newIdx = idx + x;
16            if (newIdx >= n || x > d || nums[idx] <= nums[newIdx]) break;
17        
18            f1 = false;
19            res = max (res, solve (nums, d, newIdx) + 1);
20            x += 1;
21        }
22        x = 1;
23        while (true) {
24            int newIdx = idx - x;
25            if (newIdx < 0 || x > d || nums[idx] <= nums[newIdx]) break;
26            f2 = false;
27            res = max (res, solve (nums, d, newIdx) + 1);
28            x += 1;
29        }
30
31        return dp[idx] = res;
32
33
34    }
35    int maxJumps(vector<int>& nums, int d) {
36        n = nums.size();
37        int i = n - 1;
38        int mx = 0;
39        while (i >= 0) {
40            mx = max (mx , solve (nums, d, i));
41            i -= 1;
42        }
43
44        return mx;
45    }
46};