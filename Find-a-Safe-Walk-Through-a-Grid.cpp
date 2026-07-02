1class Solution {
2public:
3    bool findSafeWalk(vector<vector<int>>& grid, int health) {
4        // vector <vector<int>> dist
5
6        int m = grid.size();
7        int n = grid[0].size();
8
9        using t = tuple <int, int,int>;
10        priority_queue <t, vector<t>, greater<>> pq;
11
12
13        int dir[5] = {0 , 1, 0, -1, 0};
14        // vector<vector<int>> visited (m, vector<int> (n, 0));
15        vector<vector<vector<int>>> dist (m, vector<vector<int>> (n, vector<int> (health + 1, INT_MAX)));
16        pq.push({grid[0][0], 0, 0});
17        dist[0][0][grid[0][0]] = 0;
18
19        while (pq.size()) {
20            auto [h, i, j] = pq.top();
21            pq.pop();
22            // cout << h << " " << i <<" " << j << endl;
23            // visited[i][j] = 1;
24
25            for (int x = 0; x < 4; x += 1) {
26                int rx = i + dir[x];
27                int ry = j + dir[x + 1];
28                if (rx >= 0 && ry >= 0 && rx < m && ry < n) {
29                    int nh = h + grid[rx][ry];
30                    // cout << i << " " << j << " " << h << " " << dist[i][j][h] << " " << nh <<  endl;
31                    if (nh < health && dist[i][j][h] + grid[rx][ry] < dist[rx][ry][nh]) {
32                        dist[rx][ry][nh] = dist[i][j][h] + grid[rx][ry];
33                        pq.push({nh, rx, ry});
34                    }
35                }
36                
37            }
38        }
39
40        for (int i = 0; i < health; i += 1) {
41            if (dist[m -1][n -1][i] != INT_MAX) return true;
42        }
43        return false;
44    }
45};