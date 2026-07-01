1class Solution {
2public:
3    int maximumSafenessFactor(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
8            return 0;
9
10        vector<pair<int, int>> idx;
11
12        for (int i = 0; i < m; i++) {
13            for (int j = 0; j < n; j++) {
14                if (grid[i][j] == 1) {
15                    idx.push_back({i, j});
16                }
17            }
18        }
19
20        vector<vector<int>> one_dist(m, vector<int>(n, -1));
21        queue<pair<int, int>> q;
22
23        for (auto& i : idx) {
24            int r = i.first;
25            int c = i.second;
26
27            one_dist[r][c] = 0;
28            q.push({r, c});
29        }
30
31        vector<int> dr = {-1, 1, 0, 0};
32        vector<int> dc = {0, 0, -1, 1};
33
34        while (!q.empty()) {
35            auto [r, c] = q.front();
36            q.pop();
37
38            for (int k = 0; k < 4; k++) {
39                int nr = r + dr[k];
40                int nc = c + dc[k];
41
42                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
43                    one_dist[nr][nc] == -1) {
44                    one_dist[nr][nc] = one_dist[r][c] + 1;
45                    q.push({nr, nc});
46                }
47            }
48        }
49        using t = tuple <int,int,int>; // min, i, j
50        priority_queue <t> pq;
51
52        pq.push ({one_dist[0][0], 0, 0});
53        vector<vector<int>> visited(m, vector<int>(n, 0));
54        visited[0][0] = 1;
55        
56        while (pq.size()) {
57            auto [mx, r, c] = pq.top();
58            pq.pop();
59
60            if (r == m - 1 && n - 1 == c) {
61                return min (one_dist[r][c], mx);
62            }
63
64            for (int k = 0; k < 4; k++) {
65                int nr = r + dr[k];
66                int nc = c + dc[k];
67
68                 if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
69                    one_dist[nr][nc] != 0 && !visited[nr][nc]) {
70                        pq.push ({min(mx, one_dist[nr][nc]), nr, nc});
71                        visited[nr][nc] = 1;
72                }
73            }
74        }
75        return 0;
76    }
77};