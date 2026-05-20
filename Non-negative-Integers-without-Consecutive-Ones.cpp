1class Solution {
2public:
3    string s;
4    int dp[32][2][2] = {};
5    int solve (int idx, bool tight, bool isone) {
6        if (idx == s.size()) return 1;
7        int & ans = dp[idx][tight][isone];
8
9        if (ans != -1) return ans;
10
11        int lim = (tight) ? s[idx] - '0' : 1;
12        int res = 0;
13
14        for (int i = 0; i <= lim; i += 1) {
15            int nxt_tight = (tight && s[idx] - '0' == i);
16
17            if (i == 1 && isone) break;
18            
19            res += solve (idx + 1, nxt_tight, i == 1);
20        }
21        return ans =res;
22    }
23    int findIntegers(int n) {
24        s = bitset<32>(n).to_string();
25        memset (dp, -1, sizeof(dp));
26        return solve (0, s[0] == '0', 0);
27    }
28};