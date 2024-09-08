class Solution {
public:
    vector<int> parent;
    vector<int> size;
    void set(int k) {
        parent.resize(k);
        size.resize(k, 1);
        for (int i = 0; i < k; i++)
            parent[i] = i;
    }
    int findP(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = findP(parent[u]);
    }
    void uf(int u, int v) {
        u = findP(u), v = findP(v);
        if (u == v);
        else {
            if (size[u] < size[v]) {
                parent[u] = v;
                size[v] += size[u];
            } else {
                parent[v] = u;
                size[u] += size[v];
            }
        }
    }
    int answer(vector<vector<int>> grid, int m, int n) {
        int cnt = 0, p = 0;
        int k = findP(0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int b = findP(p);
                if (grid[i][j] && k != b)
                    cnt++;
                p++;
            }
        }
        return cnt;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        int m = grid.size();
        int n = grid[0].size();
        set(m * n + 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int curridx = (i * n) + j;
                    if ((i == 0 || j == 0 || i == m - 1 || j == n - 1))
                        uf(0, curridx);
                     else if (grid[i][j]){
                        if (grid[i + 1][j] == 1)
                            uf(curridx, curridx + n);
                        if (grid[i - 1][j] == 1)
                            uf(curridx - n, curridx);
                        if (grid[i][j + 1] == 1)
                            uf(curridx, curridx + 1);
                        if (grid[i][j - 1] == 1)
                            uf(curridx - 1, curridx);
                    }
                }
        }
        return answer(grid, m, n);
    }
};