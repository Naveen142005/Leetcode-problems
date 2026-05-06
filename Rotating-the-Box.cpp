1class Solution {
2public:
3    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
4        int m = boxGrid.size();
5        int n = boxGrid[0].size();
6        vector<vector<char>> ans (n, vector<char>(m));
7
8        for (auto& nums: boxGrid) {
9            int i = nums.size() - 2, j = nums.size() - 1;
10
11            while (i >= 0 && j >= 0) {
12                
13                if (nums[j] == '*') {
14                    j -= 1;
15                    i = j - 1;
16                    continue;
17                }
18                
19                if (nums[i] == '*') {
20                    i -= 2;
21                    j = i + 1;
22                    continue;
23                }
24
25                if (nums[j] == '#') {
26                    j -= 1;
27                    i -= 1;
28                    continue;
29                }
30
31                if (nums[i] == '.') {
32                    i -= 1;
33                    continue;
34                }
35
36                if (nums[i] == '#' && nums[j] == '.') {
37                    swap (nums[i], nums[j]);
38                    i -= 1;
39                    j -= 1;
40                    continue;
41                }
42                
43                
44            }
45        }
46
47        // for (auto i: boxGrid){
48        //     for( auto j: i) cout << j << " ";
49        //     cout << '\n';
50        // }
51        for (int i = 0; i < n; i += 1) {
52            for (int j = 0; j < m; j += 1) {
53                ans[i][j] = boxGrid[j][i];
54            }
55            reverse(ans[i].begin(), ans[i].end());
56        }
57        return ans;
58    }
59};