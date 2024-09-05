class Solution {
public:
    vector<int> parent;
    vector<int> size;
    void set(int k) {
        parent.resize(k );
        size.resize(k ,1);
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
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        ios_base::sync_with_stdio(false);
        vector<bool> _restricted(n+1,true);
        set(n);
        for (auto i : restricted)
            _restricted[i] = _restricted[i] = false;
        for (auto i : edges) 
            if (_restricted[i[0]] && _restricted[i[1]])
                uf (i[0],i[1]);
        int zero_p = findP(0);
        int cnt = 0;
        for (int i = 0 ; i < n ; i++)
            if (findP(i) == zero_p) cnt++;
        return cnt;
        
        
    }
};