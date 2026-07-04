class Solution {
public:
    vector <int> parent;
    vector <int> size;
    vector <int> mx;

    void set (int n) {
        parent.resize(n);
        size.resize(n, 1);
        mx.resize(n , INT_MAX);
        for (int i = 0; i < n; i += 1) {
            parent[i] = i;
        }
    }

    int findP (int p) {
        if (p == parent[p]) return p;
        return parent[p] = findP(parent[p]);
    }
    void uf (int u, int v, int val) {
        // cout << u << " " << v << " " ;
        u = findP(u), v = findP(v);

        // if (size[u] <= size[v]) {
            parent[u] = v;
            // size[v] += size[u];
            // v = findP(v);
            mx[v] = min (mx[v], val);
            // cout << v << " " << mx[v] << endl;
        // }
        // else { 
            // parent[v] = u;
            // size[u] += size[v];
            // u = findP(u);
            // mx[u] =. min(mx[u], val);
            // cout << u << " " << mx[u] << endl;
        // }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        set(n + 1);
        int mxx = INT_MAX;

        for (auto& i: roads) {
            uf (i[0], i[1], i[2]);
            // mxx = min(mxx, i[2]);
        }

        if (findP(1) != findP(n)) return -1;
        for (int i = 1; i <= n; i += 1) {
            // cout << i << " = " << findP(i) << " " << mx[parent[i]] << endl; 
        }
        int p = findP(1);

        for (int i = 1; i <= n; i += 1) {
            if (p == findP(i))
                mxx = min(mxx, mx[i]);
        }
        // return min (mx[findP(1)] , mx[findP(n)]);
        return mxx;
    }
};