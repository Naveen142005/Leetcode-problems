1class Solution {
2public:
3    int countSubmatrices(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6        int cnt = (grid[0][0] <= k);
7
8        for (int i = 1; i < m; i += 1) {
9            grid[i][0] += grid[i - 1][0];
10            if (grid[i][0] <= k) cnt += 1;
11        }   
12
13        for (int i = 1; i < n; i += 1) {
14            grid[0][i] += grid[0][i - 1];
15            if (grid[0][i] <= k) cnt += 1;
16        }
17        for (int i = 1; i < m; i += 1) {
18            for (int j = 1; j < n; j += 1) {
19                grid[i][j] = (grid[i][j - 1] + grid[i - 1][j]) - grid[i - 1][j - 1] + grid[i][j];
20                if (grid[i][j] <= k) cnt += 1;
21            }
22        }
23
24        return cnt;
25    }
26};