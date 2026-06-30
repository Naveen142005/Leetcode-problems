1class Solution {
2public:
3    int dp[10][2][2][12];
4    int solve (string& str, int tight, int idx, bool lz, int cnt) {
5        if (idx == str.size()) return cnt;
6
7        if (dp[idx][tight][lz][cnt] != -1) return dp[idx][tight][lz][cnt];
8        int lim = tight ? str[idx] - '0' : 9;
9
10        int res = 0;
11
12        for (int i = 0; i <= lim; i += 1) {
13            int nxt = (tight && i == str[idx] - '0');
14
15            if (i == 0 && lz) {
16                res += solve (str, nxt, idx + 1, 1, cnt);
17                continue;
18            }
19
20            res += solve (str, nxt, idx + 1, lz, cnt + (i == 1));
21        }
22
23        return dp[idx][tight][lz][cnt]  = res;
24    }
25
26    int countDigitOne(int n) {
27        string str = to_string (n);
28        memset(dp, -1, sizeof(dp));
29        return solve (str, 1, 0, 1, 0);
30    }
31};