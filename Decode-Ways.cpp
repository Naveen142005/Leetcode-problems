1class Solution {
2public:
3    int dp[101];
4    int solve (int idx, string& s) {
5        if (idx == s.size()) return 1;
6        if (dp[idx] != -1) return dp[idx];
7        
8        int res = 0;
9        int d = 0;
10        string t = "";
11        for (int i = idx; i < s.size(); i += 1) {
12            t += s[i];
13            if (t[0] == '0') break;
14            if (t.size() >= 3) break;
15
16            int y = stoi(t);
17
18            if (y >= 27) break;
19
20            res += solve (i + 1, s);
21        }
22        return dp[idx] = res;
23    }
24    int numDecodings(string s) {
25        memset (dp, -1, sizeof(dp));
26        return solve (0, s);
27    }
28};