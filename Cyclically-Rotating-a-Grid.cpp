1class Solution {
2public:
3    void rotate (vector<int>& nums, int k) {
4        k = k % nums.size();
5        // cout << k << " --<\n";
6        reverse(nums.begin(), nums.begin() + k);
7        reverse(nums.begin() + k, nums.end());
8        reverse(nums.begin(), nums.end());
9
10    }
11    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int chi) {
12        ios::sync_with_stdio(false);
13        cin.tie(nullptr);
14        
15    //    { // vector <int> temp;
16
17    //     // int i = 0, j = 0;
18    //     // int m = grid.size();
19    //     // int n = grid[0].size();
20
21    //     // while (i < (m/2)) {
22
23    //     //     for (int x = i; x < n - i - 1; x += 1) {
24    //     //         temp.push_back(grid[i][x]);
25    //     //     }
26
27    //     //     bool f = true;
28    //     //     for (int x = i; x < m - i - 1; x += 1) {
29    //     //         if (f) {
30    //     //             f = false;
31    //     //             continue;
32    //     //         }
33    //     //         temp.push_back(grid[x][n - i - 1]);
34    //     //     }
35
36    //     //     f = true;
37    //     //     for (int x = n - i - 1; x >= 0; x -= 1) {
38    //     //         if (f) {
39    //     //             f = false;
40    //     //             continue;
41    //     //         }
42    //     //         temp.push_back(grid[m - i - 1][x]);
43    //     //     }
44
45    //     //     f = true;
46    //     //     for (int x = m - i - 1; x >= 0; x -= 1) {
47    //     //         if (f) {
48    //     //             f = false;
49    //     //             continue;
50    //     //         }
51    //     //         temp.push_back(grid[m - i - 1][i]);
52    //     //     }
53    //     //     i += 1;
54
55    //     //     for (auto i: temp) cout << i << " ";
56    //     //     cout << '\n';
57    //     // }
58    //     // return grid;
59    //    }
60
61
62        int l = 0, m = grid.size() - 1, n = grid[0].size() - 1, k = 0;
63        vector<vector<int>> big_temp;
64
65        vector<int> temp;
66        while (l <= n && k <= m) {
67            temp.clear();
68            for (int i = l; i <= n; i += 1) {
69                temp.push_back(grid[k][i]);
70            }
71            k += 1;
72
73            for (int i = k; i <= m; i += 1) {
74                temp.push_back(grid[i][n]);
75            }
76            n -= 1;
77
78            if (k <= m) {
79                for (int i = n; i >= l; i -= 1) {
80                    temp.push_back(grid[m][i]);
81                }
82                m -= 1;
83            }
84
85            if (l <= n) {
86                for (int i = m; i >= k; i -= 1) {
87                    temp.push_back(grid[i][l]);
88                }
89                l += 1;
90            }
91            // for (auto i: temp) cout << i << " ";
92            // cout << endl;
93            rotate(temp, chi);
94            // for (auto i: temp) cout << i << " ";
95            // cout << endl;
96            big_temp.push_back(temp);
97        }
98        
99        int idx = 0;
100        int jdx = 0;
101        l = 0, m = grid.size() - 1, n = grid[0].size() - 1, k = 0;
102        while (l <= n && k <= m) {
103            jdx = 0;
104            for (int i = l; i <= n; i += 1) {
105                // temp.push_back(grid[k][i]);
106                grid[k][i] = big_temp[idx][jdx++];
107            }
108            k += 1;
109
110            for (int i = k; i <= m; i += 1) {
111                // temp.push_back(grid[i][n]);
112                grid[i][n] = big_temp[idx][jdx++];
113            }
114            n -= 1;
115
116            if (k <= m) {
117                for (int i = n; i >= l; i -= 1) {
118                    // temp.push_back(grid[m][i]);
119                    grid[m][i] = big_temp[idx][jdx++];
120                }
121                m -= 1;
122            }
123
124            if (l <= n) {
125                for (int i = m; i >= k; i -= 1) {
126                    // temp.push_back(grid[i][l]);
127                    grid[i][l] = big_temp[idx][jdx++];
128                }
129                l += 1;
130            }
131            idx += 1;
132        }
133        return grid;
134    }
135};