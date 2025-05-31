class Solution {
public:
    int dir[2][2] = {{0 , 1} , {1 , 0}};
    int m , n;
    const int mod = 1000000007;
    int dfs (vector<vector<vector<int>>> &dp , vector<vector<int>>& grid , int k , int idx , int jdx , int sum) {
        if (idx == m -1 && jdx == n -1) {
             if (!((sum + grid[idx][jdx]) % k)) return 1;
            return 0;
        }
        if (dp[idx][jdx][sum % k] != -1) return dp[idx][jdx][sum % k];
        int res = 0 , temp = grid[idx][jdx];
        grid[idx][jdx] = -1;
        for (int i = 0 ; i < 2 ; i += 1) {
            int ni = idx + dir[i][0];
            int nj = jdx + dir[i][1];
            if (ni < m && nj < n && grid[ni][nj] != -1) {
                res = (res + dfs (dp , grid , k , ni , nj ,  (temp + sum) % k)) % mod;
            }
        }
        grid[idx][jdx] = temp;
        return dp[idx][jdx][sum % k] = (res);
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size() , n = grid[0].size();
        vector<vector<vector<int>>> dp (m , vector<vector<int>> (n , vector<int> (k , -1)));

        return dfs (dp , grid , k , 0 , 0 , 0);
    }
};