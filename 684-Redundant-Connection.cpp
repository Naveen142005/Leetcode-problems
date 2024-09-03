class unionfind {
public:
    vector<int> parent;
    vector<int> rank;
    unionfind(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        rank.resize(n + 1, 1);
    }
    int findP(int u) {
        if (u != parent[u]) {
            parent[u] = findP(parent[u]);
        }
        return parent[u];
    }
    void SetPeople(int u, int v, bool& f, vector<int>& ans) {
        int k = u , l = v;
         u = findP(u), v= findP(v);
        if (u == v) {
            f = false;
            ans[0] = k;
            ans[1] = l;
            return;
        }
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            ++rank[u];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        int n = edges.size();
        unionfind uf(n);
        bool f = true;
        vector<int> ans(2);
        for (auto i : edges) {
            if (!f)
                break;
            uf.SetPeople(i[0], i[1], f, ans);
        }
        return ans;
    }
};
