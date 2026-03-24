1class Solution {
2public:
3    using ll = long long;
4    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
5        int m = grid.size();
6        int n = grid[0].size();
7        const int mod = 12345;
8        ios::sync_with_stdio(false);
9        cin.tie(nullptr);
10        
11        vector<vector<int>> ans (m, vector<int> (n, 1));
12
13        ll pp = 1LL * grid[0][0];
14        for (int i = 0; i < m; i += 1) {
15            for (int j = 0; j < n; j += 1) {
16                if (i == 0 && j == 0) continue;
17                ans[i][j] = (ans[i][j] * pp) % mod;
18                pp = (pp * grid[i][j]) % mod;
19            }
20        }
21
22        pp = 1LL * grid[m - 1][n - 1];
23        for (int i = m - 1; i >= 0; i -= 1) {
24            for (int j = n - 1; j >= 0; j -= 1) {
25                if (i == m - 1 && j == n - 1) continue;
26                ans[i][j] = (ans[i][j] * pp) % mod;
27                pp = (pp * grid[i][j]) % mod;
28            }
29        }
30        return ans;
31    }
32};