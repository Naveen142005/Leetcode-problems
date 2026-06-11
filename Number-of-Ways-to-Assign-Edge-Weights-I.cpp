1class Solution {
2public:
3    int dfs (vector<vector<int>>& adj, vector<bool>& visited, int idx, int cnt) {
4        // cout << idx <<  endl;
5        if (visited[idx]) return -1;
6        visited[idx] = true;    
7        int mx = -1;
8        for (auto& i: adj[idx]) {
9            mx = max (mx, dfs (adj, visited, i, cnt + 1));
10        }
11
12        return max (cnt, mx);
13    }
14
15
16    int assignEdgeWeights(vector<vector<int>>& edges) {
17        int n = edges.size() + 1;
18        vector <vector<int>> adj(n + 1);
19
20        for (auto& i: edges) {
21            adj[i[0]].push_back(i[1]);
22            adj[i[1]].push_back(i[0]);
23        }
24
25        vector <bool> visited (n + 1, false);
26
27        int mx = dfs (adj, visited,1, 0) - 1;
28        // cout << mx << " ";
29        const long long mod = 1e9 + 7;
30
31        long long base = 2;
32        n = mx;
33        long long res = 1;
34        
35        while (n) {
36            if (n & 1) 
37                res = (res * base) % mod;
38            base = (base * base) % mod;
39            n >>= 1;
40        }
41        return (int)res;
42       
43    }
44};