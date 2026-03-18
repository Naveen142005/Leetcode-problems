1class Solution {
2public:
3    bool canPartitionGrid(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6        using ll = long long;
7
8        vector<ll> row(m, 0);
9        row[0] = accumulate(grid[0].begin(), grid[0].end(), 0LL);
10
11        for (int i = 1; i < m; i += 1) {
12            row[i] = accumulate(grid[i].begin(), grid[i].end(), 0LL);
13            row[i] += row[i - 1];
14        }
15        int i = 0;
16        while (i < m) {
17            if (row[m - 1] - row[i] == row[i])
18                return true;
19            i += 1;
20        }
21
22        vector<ll> col(n, 0);
23        ll sum = 0;
24
25        for (int i = 0; i < n; i += 1) {
26            sum = 0;
27            for (int j = 0; j < m; j += 1) {
28                // cout << j << " " << i << '\n';
29                sum = sum + (ll)1LL * grid[j][i];
30                // cout << sum << " ";
31            }
32            // cout << '\n';
33            col[i] += sum + ((i > 0) ? col[i - 1] : 0);
34        }
35
36        i = 0;
37        while (i < n) {
38            if (col[n - 1] - col[i] == col[i])
39                return true;
40            i += 1;
41        }
42        return false;
43    }
44};