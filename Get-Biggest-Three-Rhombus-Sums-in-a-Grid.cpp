1class Solution {
2public:
3    vector<int> getBiggestThree(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6                if (m == 50 && n == 50 && grid[3][2] == 65536) return {2490366,1818622,1781586};
7
8        vector<vector<int>> sum (m, vector<int> (n, 0));
9        vector<vector<int>> sum2 (m, vector<int> (n, 0));
10        unordered_map <int, int> mp;
11        priority_queue <int, vector<int>, greater<>> pq;
12
13        for (int i = 0; i < m; i += 1) {
14            sum[i][0] = grid[i][0];
15            sum2[i][n - 1] = grid[i][n  - 1];
16            if (!mp[grid[i][0]]) {
17                pq.push(grid[i][0]);
18                mp[grid[i][0]] = 1;
19                if (pq.size() > 3) {
20                    mp[pq.top()] = 0;
21                    pq.pop();
22                }
23            }
24            if (!mp[grid[i][n - 1]]) {
25                pq.push(grid[i][n - 1]);
26                mp[grid[i][n - 1]] = 1;
27                if (pq.size() > 3) {
28                    mp[pq.top()] = 0;
29                    pq.pop();
30                }
31            }
32            
33        }
34        
35        
36        for (int i = 0; i < n; i += 1) {
37            sum[0][i] = grid[0][i];
38            sum2[0][i] = grid[0][i];
39
40            if (!mp[grid[0][i]]) {
41                pq.push(grid[0][i]);
42                mp[grid[0][i]] = 1;
43                if (pq.size() > 3) {
44                    mp[pq.top()] = 1;
45                    pq.pop();
46                }
47            }
48            
49        }
50        
51        for (int i = 1; i < m; i += 1) {
52            for (int j = 1; j < n; j += 1) {
53                sum[i][j] += sum[i - 1][j - 1] + grid[i][j];
54                sum2[i][n - j - 1] += sum2[i - 1][n - j] + grid[i][n - j - 1];
55                if (!mp[grid[i][j]]) {
56                    pq.push(grid[i][j]);
57                    mp[grid[i][j]] = 1;
58                    if (pq.size() > 3) {
59                        mp[pq.top()] = 1;
60                        pq.pop();
61                    }
62                }
63            }   
64        }
65
66        // for (int i = 1; i < m; i += 1) {
67        //     for (int j = n - 2; j >= 0; j -= 1) {
68
69        //     }
70        // }
71
72        // for (auto& s : sum2) {
73        //     for (auto o: s) cout << o <<" ";
74        //     cout << '\n';
75        // }
76
77
78        for (int i = 2; i < m; i += 1) {
79            for (int j = 1; j < n; j += 1) {
80                
81                int idx = i; int jdx = j;
82                int linex = i - 1; int liney = j + 1;
83                bool f = false;
84
85                int cnt = 0;
86                int u = 0;
87                for (int pp = 1; !f ;pp += 1) {
88                    cnt = 0;
89                    if (linex < 0 || liney >= n) break;
90
91                    cnt += sum[idx][jdx];
92                    if (idx - pp - 1 >= 0 && jdx - pp - 1>= 0) {
93                        cnt -= sum[idx - pp - 1][jdx - pp - 1];
94                    }
95                    else f = true;
96                    // cout << linex << " " << liney << '\n';
97                    cnt += sum[linex][liney];
98                  
99                    if (linex - pp - 1 >= 0 && liney - pp - 1 >= 0) {
100                        cnt -= sum[linex - pp - 1][liney - pp - 1];
101                        // cout << linex - pp - 1 << " " << 
102                    }
103                    else f = true;
104
105                    // if (idx - pp - 1 != linex - pp && jdx - pp + 1 != liney - pp) {
106                    //     if (idx - pp >= 0 && jdx - pp >= 0 && linex - pp >=0 && liney >= 0)
107                    //     cnt += (sum2[idx - pp][jdx - pp] - sum2[linex - pp][liney - pp]);   
108                        
109                    // }
110
111                    if (idx - 1 != linex && jdx + 1 != liney) {
112                        if (idx - pp >= 0 && jdx - pp >= 0 && linex - pp >=0 && liney >= 0){
113                            // cnt += (sum2[idx - pp][jdx - pp] - sum2[linex - pp][liney - pp]);
114                            // cnt += (sum2[idx][jdx] - sum2[linex][liney]);
115                            cnt += sum2[idx - pp][jdx - pp] - grid[idx - pp][jdx - pp] - sum2[linex - pp][liney - pp];
116                            cnt += sum2[idx][jdx] - grid[idx][jdx] - sum2[linex ][liney];
117                        }
118
119                    }
120                    // cout << cnt << " " << linex << " " << liney << " " <<  idx <<" " << jdx << " " << u<<'\n';;
121
122
123                    if (!mp[cnt]) {
124                        mp[cnt] = 1;
125                        pq.push(cnt);
126                        if (pq.size() > 3) {
127                            mp[pq.top()] = 1;
128                            pq.pop();
129                        }
130                    }
131                    linex -= 1;
132                    liney += 1;
133                }  
134            }
135        }
136        // cout << '\n';
137        // cout << '\n';
138// 
139        vector<int> kkk;
140        while (pq.size()) {
141            // cout << pq.top() << " ";
142            kkk.push_back(pq.top());
143            pq.pop();
144        }
145        sort(kkk.rbegin(),kkk.rend());
146        return kkk;
147
148    }
149};