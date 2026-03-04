1class Solution {
2public:
3    int m, n;
4    int solve(int p1_idx, int p1_jdx, int p2_idx, int p2_jdx,
5              vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& dp) {
6
7        // int p1_jdx = (p2_idx + p2_jdx) - p1_idx;
8
9        if (!(p1_idx < m && p2_idx < m && p1_jdx < n && p2_jdx < n && p1_idx >= 0 && p2_idx >= 0 && p1_jdx >= 0 && p2_jdx >= 0 &&
10            grid[p1_idx][p1_jdx] != -1 && grid[p2_idx][p2_jdx] != -1)) return -1e6;
11
12
13        int ch = 0;
14
15        if (p1_idx == p2_idx && p1_jdx == p2_jdx) {
16            ch += grid[p1_idx][p2_jdx];
17        } else {
18            ch += grid[p1_idx][p1_jdx] + grid[p2_idx][p2_jdx];
19        }   
20        // cout << ch << " ";
21        if (p1_idx == m - 1)
22            return ch;
23        if (p2_idx == m - 1)
24            return ch;
25        // cout << p1_idx << " " << p1_jdx << " " << p2_idx << " " << p2_jdx << '\n';
26         if (dp[p1_idx][p1_jdx][p2_idx][p2_jdx] != -1) return dp[p1_idx][p1_jdx][p2_idx][p2_jdx];
27
28        /*
29            Possible moves:
30                R1 | R2
31                1) left-down | left-down
32                2) left-down | down
33                3) left-down | right-down
34
35                4) down      | right-down
36                5) down      | down
37                6) down      | left-down
38
39                7) right-down| left-down
40                8) right-down| down
41                9) right-down| right-down
42
43            Indexes:
44                left-down -> (i + 1, j - 1)
45                down -> (i + 1, j)
46                right-down -> (i + 1, j + 1)
47        */
48
49        vector<int> d(9, -1);
50        d[1 - 1] = solve (p1_idx + 1, p1_jdx - 1, p2_idx + 1, p2_jdx - 1, grid, dp);
51        d[2 - 1] = solve (p1_idx + 1, p1_jdx - 1, p2_idx + 1, p2_jdx , grid, dp);
52        d[3 - 1] = solve (p1_idx + 1, p1_jdx - 1, p2_idx + 1, p2_jdx + 1, grid, dp);
53
54        d[4 - 1] = solve (p1_idx + 1, p1_jdx, p2_idx + 1, p2_jdx + 1, grid, dp);
55        d[5 - 1] = solve (p1_idx + 1, p1_jdx, p2_idx + 1, p2_jdx, grid, dp);
56        d[6 - 1] = solve (p1_idx + 1, p1_jdx, p2_idx + 1, p2_jdx - 1, grid, dp);
57
58        d[7 - 1] = solve (p1_idx + 1, p1_jdx + 1, p2_idx + 1, p2_jdx - 1, grid, dp);
59        d[8 - 1] = solve (p1_idx + 1, p1_jdx + 1, p2_idx + 1, p2_jdx, grid, dp);
60        d[9 - 1] = solve (p1_idx + 1, p1_jdx + 1, p2_idx + 1, p2_jdx + 1, grid, dp);
61
62    
63        return  dp[p1_idx][p1_jdx][p2_idx][p2_jdx] = ch + (*max_element(d.begin(), d.end()));
64        
65    }
66    int cherryPickup(vector<vector<int>>& grid) {
67        m = grid.size();
68        n = grid[0].size();
69        // memset (dp, -1, sizeof(dp));
70        
71        vector<vector<vector<vector<int>>>> dp (m, 
72            vector<vector<vector<int>>> (n, 
73                vector<vector<int>>(m, 
74                    vector<int> (n, -1)
75                )
76            )
77        );
78
79        // cout << m << " " << n << '\n';
80        
81        int ans = solve(0, 0, 0, n - 1, grid, dp);
82        if (ans <= 0) return 0;
83        return ans;
84    }
85};