class Solution {
public:
    vector<int> parent;
    vector<int> size;
    void set(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i += 1) {
            parent[i] = i;
        }
    }
    int findP(int p) {
        if (p == parent[p]) {
            return p;
        }
        return parent[p] = findP(parent[p]);
    }
    void uf(int u, int v) {
        u = findP(u), v = findP(v);
        if (u != v) {
            if (size[u] < size[v]) {
                parent[u] = v;
                size[v] += size[u];
            } else {
                parent[v] = u;
                size[u] += size[v];
            }
        }
    }
    bool equationsPossible(vector<string>& equations) {
        set(26);

        for (auto& st : equations)
            if (st[1] == st[2])
                uf(st[0] - 'a', st[3] - 'a');

        for (auto& st : equations)
            if (st[1] != st[2] &&  (findP(st[0] - 'a') == findP(st[3] - 'a'))) 
                return false;
                
        return true;
    }
};