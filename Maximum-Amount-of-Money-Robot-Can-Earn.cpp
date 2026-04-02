1class Solution {
2public:
3    int m, n;
4    // int dp[505][505][3];
5
6    // int dfs(int i, int j, int cnt, vector<vector<int>>& coins) {
7    //     if (i >= m || j >= n) return -1e9;
8
9    //     if (dp[i][j][cnt] != -1) return dp[i][j][cnt];
10
11    //     if (i == m - 1 && j == n - 1) {
12    //         if (coins[i][j] >= 0) return dp[i][j][cnt] = coins[i][j];
13    //         else {
14    //             if (cnt < 2) {
15    //                 return dp[i][j][cnt] = 0;
16    //             }
17    //             return dp[i][j][cnt] = coins[i][j];
18    //         }
19    //     }
20
21    //     int left = -1e9, right = -1e9;
22    //     int ans = -1e9;
23
24    //     if (coins[i][j] >= 0) {
25    //         left = dfs(i + 1, j, cnt, coins);
26    //         right = dfs(i, j + 1, cnt, coins);
27    //         ans = max(ans, coins[i][j] + max(left, right));
28    //     } else {
29    //         if (cnt < 2) {
30    //             left = dfs(i + 1, j, cnt + 1, coins);
31    //             right = dfs(i, j + 1, cnt + 1, coins);
32    //             ans = max(ans, max(left, right));
33    //         }
34
35    //         left = dfs(i + 1, j, cnt, coins);
36    //         right = dfs(i, j + 1, cnt, coins);
37    //         ans = max(ans, coins[i][j] + max(left, right));
38    //     }
39
40    //     return dp[i][j][cnt] = ans;
41    // }
42
43    int maximumAmount(vector<vector<int>>& coins) {
44        ios::sync_with_stdio(false);
45        cin.tie(nullptr);
46        
47        m = coins.size();
48        n = coins[0].size();
49        // memset(dp, -1, sizeof(dp));
50        // return dfs(0, 0, 0, coins);
51
52        vector<vector<vector<int>>> dp(m + 1 , vector<vector<int>>(n + 1, vector<int>(3,-1e9)));
53
54        if (coins[m - 1][n - 1] >= 0) {
55            dp[m - 1][n - 1][0] = coins[m - 1][n - 1];
56            dp[m - 1][n - 1][1] = coins[m - 1][n - 1];
57            dp[m - 1][n - 1][2] = coins[m - 1][n - 1];
58        }
59
60        else {
61            dp[m - 1][n - 1][0] = 0;
62            dp[m - 1][n - 1][1] = 0;
63            dp[m - 1][n - 1][2] = coins[m - 1][n - 1];
64        }
65
66        for (int i = m - 1; i >= 0; i -= 1){
67            for (int j = n - 1; j >= 0; j -= 1) {
68                for (int cnt = 0; cnt < 3; cnt += 1) {
69                        if (coins[i][j] >= 0) {
70                            dp[i][j][cnt] = max(dp[i][j][cnt], 
71                                                coins[i][j] + max (dp[i + 1][j][cnt], dp[i][j + 1][cnt])
72                                        );
73                        }
74                        else {
75                            if (cnt < 2) {
76                                dp[i][j][cnt] = max ({dp[i][j][cnt], dp[i + 1][j][cnt + 1], dp[i][j + 1][cnt + 1]});
77                            }
78                            
79                            dp[i][j][cnt] = max(dp[i][j][cnt], 
80                                            coins[i][j] + max (dp[i + 1][j][cnt], dp[i][j + 1][cnt])
81                                    );
82                            
83                        }
84
85                }                
86            }
87        }
88
89        return dp[0][0][0];
90    }
91};