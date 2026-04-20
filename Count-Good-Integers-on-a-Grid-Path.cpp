1class Solution {
2public:
3    using ll = long long;
4    ll dp[17][2][10];
5    int is_path[16] = {0};
6    ll solve (string& s, int idx, int tight, int prev) {
7        if (idx == 16) {
8            return 1;
9        } 
10        if (dp[idx][tight][prev] != -1) return dp[idx][tight][prev];
11        int limit = (tight) ? (s[idx] - '0') : 9;
12
13        ll res = 0;
14        for (int i = 0; i <= limit; i += 1) {
15            if (is_path[idx]) {
16                if (i >= prev) {
17                    res += solve(s, idx + 1, (tight && i == s[idx] - '0'), i);
18                }
19            }
20            else {
21                res += solve(s, idx + 1, (tight && i == s[idx] - '0'), prev); 
22            }
23        }
24        return dp[idx][tight][prev] = res;
25    }
26
27    ll solver (ll n, string& dir) {
28        string s = to_string(n);
29        string temp = "";
30
31        for (int i = 0; i < 16 - s.size(); i += 1) 
32            temp += "0";
33        s = temp + s;
34
35        int x = 0;
36
37        string fin = "";
38        int i = 0, j = 0;
39
40        memset (is_path, 0, sizeof(is_path));
41        memset (dp, -1, sizeof(dp));
42
43        is_path[0] = 1;
44
45        while (x <= dir.size()) {
46            int curridx = (i * 4) + j;
47           
48            is_path[curridx] = 1;
49            if (dir[x] == 'D') i += 1;
50            else j += 1;
51            x += 1;
52                
53        }
54        return solve (s, 0, 1, 0);
55    } 
56    ll countGoodIntegersOnPath(ll l, ll r, string d) {
57        return solver (r, d) - solver (l - 1, d);
58    }
59};