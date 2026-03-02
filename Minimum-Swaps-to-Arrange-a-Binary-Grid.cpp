1class Solution {
2public:
3    int minSwaps(vector<vector<int>>& grid) {
4        int n = grid.size();
5
6        int tt = n - 1;
7        // while (tt > 0) {
8        //     int cnt = 0;
9        //     for (int i = 0; i < n; i += 1) {
10        //         if (grid[i][tt] == 0) cnt += 1;
11        //         if (cnt >= tt) break;
12        //     }
13        //     if (cnt < tt) return -1;
14        //     tt -= 1;
15        // }
16        // for(auto i:grid){
17        //     for(auto j:i) cout<<j<<" ";
18        //     cout<<'\n';
19        // }
20        int mx = 0;
21        unordered_map<int, vector<int>> mp;
22
23        for (int i = 0; i < n; i += 1)
24            mp[i] = grid[i];
25
26        for (int i = 0; i < n; i += 1) {
27            vector<int>& temp = mp[i];
28            bool isAllZero = true;
29            for (int x = n - 1; x >= i + 1; x -= 1) {
30                if (temp[x] != 0) {
31                    //  cout << x << '\n';
32                    isAllZero = false;
33                    break;
34                }
35            }
36
37            if (!isAllZero) {
38
39                for (int xx = i + 1; xx < n; xx += 1) {
40                    bool isOk = true;
41                    vector<int>& trav = mp[xx];
42                    for (int yy = n - 1; yy >= i + 1; yy -= 1) {
43                        if (trav[yy] != 0) {
44                            isOk = false;
45                            break;
46                        }
47                    }
48                    // cout << isOk;
49                    if (isOk) {
50                        int st = i;
51                        int end = xx;
52
53                        vector<int> endarr = mp[end];
54
55                        for (int pp = end; pp > st; pp -= 1) {
56                            mp[pp] = mp[pp - 1];
57                        }
58                        mp[st] = endarr;
59                        // cout << end << " " << st << endl;
60                        mx += (end - st);
61                        break;
62                    }
63                }
64            }
65        }
66
67        for (int i = 0; i < n; i += 1) {
68            vector<int>& temp = mp[i];
69            bool isAllZero = true;
70            for (int x = n - 1; x >= i + 1; x -= 1) {
71                if (temp[x] != 0) {
72                    // isAllZero = false;
73                    // break;
74                    return -1;
75                }
76            }
77        }
78
79        return mx;
80    }
81};