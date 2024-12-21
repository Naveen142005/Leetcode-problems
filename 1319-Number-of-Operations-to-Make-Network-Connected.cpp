class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int NonConnected = 0;
    int Connected = 0;
    int findParent(int u) {
        if (u == parent[u])
            return u;
        else
            return parent[u] = findParent(parent[u]);
    }
    void setValidPath(int n, vector<vector<int>>& edges) {
        rank.resize(n, 0);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (auto i : edges) {
            int f = findParent(i[0]), s = findParent(i[1]);

            if (parent[f] != parent[s]) {
                if (rank[f] < rank[s]) {
                    parent[f] = s;
                    rank[s]++;
                } else {
                    parent[s] = f;
                    rank[f]++;
                }
                Connected++;
            } else
                NonConnected++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        ios_base::sync_with_stdio(false);
        Connected = NonConnected = 0;
        setValidPath(n, connections);
        if (n - 1 - Connected > NonConnected) return -1;
        return (n - 1) - Connected;
    }
};