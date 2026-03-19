1class Solution {
2public:
3    vector<int> parent;
4    vector<int> size;
5    void set(int n) {
6        parent.resize(n+1);
7        size.resize(n+1, 1);
8        for (int i = 0 ; i <= n ; i += 1) {
9            parent[i] = i;
10        }
11    }
12    int findP(int p) {
13        if (p == parent[p]) {
14            return p;
15        }
16        return parent[p] = findP(parent[p]);
17    }
18    void uf (int u , int v) {
19        u = findP(u) , v = findP(v);
20        if (u != v) {
21            if (size[u] < size[v]) {
22                parent[u] = v;
23                size[v] += size[u];
24            }
25            else {
26                parent[v] = u;
27                size[u] += size[v];
28            }
29        }
30    }
31    int maxActivated(vector<vector<int>>& points) {
32        int n = points.size();
33        set (n);
34       
35        unordered_map <int, vector<int>> mp1, mp2;
36
37        for (int i = 0; i < n; i += 1) {
38            int x = points[i][0] , y = points[i][1];
39            mp1[x].push_back(i);
40            mp2[y].push_back(i);
41        }
42        
43        // for (auto i : mp1) {
44        //     vector<int>& temp = i.second;
45        //     cout << i.first << "==> " ;
46        //     // for (int x = 1; x < temp.size() - 1; x += 1) {
47        //         // cout << temp[x] << " ";
48        //         // uf (temp[x], temp[x - 1]);
49        //     // }
50            
51        //     for(int i : temp) cout << i << " ";
52        //     cout << '\n';
53
54        // }
55        // cout << "====\n";
56        // for (auto i : mp2) {
57        //     vector<int>& temp = i.second;
58        //     cout << i.first << "==> " ;
59        //     // for (int x = 1; x < temp.size() - 1; x += 1) {
60        //         // cout << temp[x] << " ";
61        //         // uf (temp[x], temp[x - 1]);
62        //     // }
63        //     for(int i : temp) cout << i << " ";
64        //     cout << '\n';
65
66        // }
67        for (auto i : mp1) {
68            vector<int>& temp = i.second;
69            for (int x = 1; x < temp.size() ; x += 1) {
70                uf (temp[x], temp[x - 1]);
71                // cout <<":4";
72            }
73        }
74        for (auto i : mp2) {
75            vector<int>& temp = i.second;
76            for (int x = 1; x < temp.size() ; x += 1) {
77                uf (temp[x], temp[x - 1]);
78            }
79        }
80        // // cout << "============\n";
81        // for (int i = 0; i < n; i += 1) 
82        //     cout << i << " " << parent[i] << '\n';
83        // cout <<"=========\n";
84        priority_queue<int, vector<int>, greater <>> pq;
85
86        for (int i = 0; i < n; i += 1) {
87            // cout << i << " " << size[i] << '\n';
88            if (findP(parent[i]) == i) pq.push(size[i]);
89            if (pq.size() > 2) pq.pop();
90        }
91
92        int cnt = 1;
93        while (pq.size()) {
94            cnt += pq.top();
95            pq.pop();
96        }
97        return cnt;
98        
99    }
100};