#define VII vector<pair<int, int>>
#define II pair<int, int>
#define PP pair<int, pair<int, int>>
#define f first
#define s second
class Solution {
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<II> q;
        int m = grid.size(), n = grid[0].size();
        int k = 0;
        for (int i = 0; i < m; i += 1) {
            for (int j = 0; j < n; j += 1) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
                if (grid[i][j] == 1)
                    k += 1;
            }
        }
        if (!k) return 0;

        int cnt = -1;

        while (q.size()) {
            int ss = q.size();
            while (ss--) {
                II p = q.front();
                q.pop();

                for (int i = 0; i < 4; i += 1) {
                    int ni = p.f + dir[i][0];
                    int nj = p.s + dir[i][1];

                    if (ni >= 0 && nj >= 0 && ni < m && nj < n) {
                        if (grid[ni][nj] == 1) {
                            q.push({ni, nj});
                            grid[ni][nj] = 0;
                            k -= 1;
                        }
                    }
                }
            }
            cnt += 1;
        }

        return k == 0 ? cnt : -1;
    }
};