class Solution {
public:
    vector<int> _cnt;
    int dfs(vector<int>& adj, vector<int>& visited, int& cnt, int idx,
            bool& f) {

        if (visited[idx] == 1) {
            cnt = cnt - _cnt[idx];
            return 1;
        }

        if (adj[idx] == -1 || visited[idx] == 2)
            return 2;
        visited[idx] = 1;

        _cnt[idx] = cnt;
        
        if (!f && dfs(adj, visited, ++cnt, adj[idx], f) == 1)
            f = true;
        
        visited[idx] = 2;
        return 2;
    }
    int longestCycle(vector<int>& edges) {
        int ss = edges.size();
        vector<int> visited(ss, 0);

        vector<vector<int>> adj(ss, vector<int>());

        _cnt.resize(ss, 0);
        int mx = -1;
        for (int i = 0; i < ss; i += 1) {
            if (visited[i] == 0) {
                int cnt = 0;
                bool flag = false;
                dfs(edges, visited, cnt, i, flag);
                if (flag)
                    mx = max(mx, cnt);
            }
        }
        return mx;
    }
};