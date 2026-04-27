1class Solution {
2public:
3    vector<int> parent;
4    vector<int> size;
5
6    void set(int m, int n) {
7        int k = m * n;
8        parent.resize(k);
9        size.resize(k , 1);
10        for (int i = 0; i < k; i++)
11            parent[i] = i;
12    }
13    int findP(int u) {
14        if (u == parent[u])
15            return u;
16        return parent[u] = findP(parent[u]);
17    }
18    void uf(int u, int v) {
19        u = findP(u), v = findP(v);
20        if (u == v)
21            return;
22        else {
23            if (size[u] < size[v]) {
24                parent[u] = v;
25                size[v] += size[u];
26            } else {
27                parent[v] = u;
28                size[u] += size[v];
29            }
30        }
31    }
32    bool hasValidPath(vector<vector<int>>& grid) {
33        int m = grid.size();
34        int n = grid[0].size();
35        set (m, n);
36
37        int nx = 0;
38        
39        for (int i = 0; i < m; i += 1) {
40            for (int j = 0; j < n; j += 1) {
41                int curridx = (i * n) + j;
42
43                if (grid[i][j] == 1) {
44                    if (j + 1 < n) {
45                        nx = grid[i][j + 1];
46                        if (nx == 1 || nx == 3 || nx == 5) {
47                            uf (curridx, curridx + 1);
48                        }
49                    }
50                    if (j - 1 >= 0){
51                        nx = grid[i][j - 1];
52                        if (nx == 1 || nx == 4 || nx == 6) {
53                            uf(curridx, curridx - 1);
54                        }
55                    }
56                }
57                else if (grid[i][j] == 2) {
58                    if (i + 1 < m) {
59                        nx = grid[i + 1][j];
60                        if (nx == 2 || nx == 5 || nx == 6) {
61                            uf (curridx, curridx + n);
62                        }
63                    }
64                    if (i - 1 >= 0) {
65                        nx = grid[i - 1][j];
66                        if (nx == 2 || nx == 3 || nx == 4) {
67                            uf (curridx, curridx - n);
68                        }
69                    }
70                }
71
72                else if (grid[i][j] == 3) {
73                    if (j - 1 >= 0) {
74                        nx = grid[i][j - 1];
75                        if (nx == 1 || nx == 4 || nx == 6) {
76                            uf (curridx, curridx - 1);
77                        }
78                    }
79                    if (i + 1 < m) {
80                        nx = grid[i + 1][j];
81                        if (nx == 2 || nx == 5 || nx == 6) {
82                            uf (curridx, curridx + n);
83                        }
84                    }
85                }
86
87                else if (grid[i][j] == 4) {
88                    if (j + 1 < n) {
89                        nx = grid[i][j + 1];
90                        if (nx == 1 || nx == 3 || nx == 5) {
91                            uf (curridx, curridx + 1);
92                        }
93                    }
94                    if (i + 1 < m) {
95                        nx = grid[i + 1][j];
96                        if (nx == 2 || nx == 5 || nx == 6) {
97                            uf (curridx, curridx + n);
98                        }
99                    }
100                }
101                else if (grid[i][j] == 5) {
102                    if (i + 1 < m) {
103                        nx = grid[i + 1][j];
104                        if (nx == 2 || nx == 3 || nx == 4) {
105                            uf (curridx, curridx + n);
106                        }
107                    }
108                    if (j - 1 >= 0){
109                        nx = grid[i][j - 1];
110                        if (nx == 1 || nx == 4 || nx == 6) {
111                            uf(curridx, curridx - 1);
112                        }
113                    }
114                }
115                else if (grid[i][j] == 6) {
116                    if (i + 1 < m) {
117                        nx = grid[i + 1][j];
118                        if (nx == 2 || nx == 3 || nx == 4) {
119                            uf (curridx, curridx + n);
120                        }
121                    }
122                    if (j + 1 < n) {
123                        nx = grid[i][j + 1];
124                        if (nx == 1 || nx == 3 || nx == 5) {
125                            uf (curridx, curridx + 1);
126                        }
127                    }
128                }
129            }
130        }
131        
132
133        return findP(0) == findP(m * n - 1);
134    }
135};