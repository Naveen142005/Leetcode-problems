class Solution {
public:
    vector<int> parent;
    vector<int> size;
    void set__(int n) {
        parent.resize(n + 2);
        size.resize(n + 2, 1);
        for (int i = 0; i < n + 2; i += 1)
            parent[i] = i;
    }
    int findP(int p) {
        if (parent[p] == p)
            return p;
        return parent[p] = findP(parent[p]);
    }

    void uf(int x, int y) {
        int u = findP(x), v = findP(y);
        if (parent[u] == parent[v])
            return;

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
    void solve(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int y = m * n + 1;
        set__(y + 2);
        

        for (int i = 0; i < n; i += 1) {
            if (grid[0][i] == 'O')
                uf(y + 2, i);

            if (grid[m - 1][i] == 'O')
                uf(y + 2, (m * n) - (n - i));
           
        }
        for (int i = 0; i < m; i += 1) {
            
            if (grid[i][0] == 'O')
                uf(y + 2, i * n);
            if (grid[i][n - 1] == 'O')
                uf(y + 2, (i + 1) * n - 1);
        }
       

        for (int i = 0; i < m; i += 1) {
            for (int j = 0; j < n; j += 1) {
                int curridx = (i * n) + j;
                if (grid[i][j] == 'O') {
                    bool flag = false;
                    if (i + 1 < m && grid[i + 1][j] == 'O')
                        uf(curridx, curridx + n), flag = true;
                    if (j + 1 < n && grid[i][j + 1] == 'O')
                        uf(curridx, curridx + 1), flag = true;
                }
            }
        }

        y = findP(y + 2);
        for (int i = 0; i < m; i += 1) {
            for (int j = 0; j < n; j += 1) {
                if (grid[i][j] == 'O' && findP(((i * n) + j)) != y)
                    grid[i][j] = 'X';
            }
        }
    }
};