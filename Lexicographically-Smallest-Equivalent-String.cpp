class Solution {
public:
    vector <int> parent;

    int find (int p) {
        if (p == parent[p]) return p;
        return parent[p] = find(parent[p]);
    }

    void uf (int u , int v) {
        u = find(u) , v = find(v);
        if (u == v) return;

        if (u < v){
            parent[v] = u;
        }
        else parent[u] = v;

    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        int ss = s1.size();
        parent.resize (26);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0 ; i < ss ; i += 1) 
            uf (s1[i] - 'a' , s2[i] - 'a');
        
        for (auto& i : baseStr) 
            i = (find (i - 'a') + 'a');
            
        return baseStr;
    }
};