const auto boost = []() { ios_base::sync_with_stdio(false); };
class Solution {
public:
    vector<int> parent;
    vector<int> size;
    void set(int n) {
        parent.resize(n+1);
        size.resize(n+1);
        for (int i = 0 ; i <= n ; i += 1) {
            parent[i] = i;
        }
    }
    int findP(int p) {
        if (p == parent[p]) {
            return p;
        }
        return parent[p] = findP(parent[p]);
    }
    void uf (int u , int v ,int& cnt) {
        u = findP(u) , v = findP(v);
        if (u != v) {
            if (size[u] < size[v]) {
                parent[u] = v;
                size[v] += size[u];
            }
            else {
                parent[v] = u;
                size[u] += size[v];
            }
            cnt++;

        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size() , cnt = 0;
        set (n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    uf(i, j,cnt);
                }
            }
        }
        return cnt;
    }
};