1class Solution {
2public:
3    long long dp[16][2][16][16][2][20];
4    long long solve(string& s, int tight, int idx, int last, int slast, int lz, int crr) {
5
6        if (idx == s.size())
7            return crr;
8
9        if (last >= 0 && slast >= 0 && dp[idx][tight][last][slast][lz][crr] != -1) 
10            return dp[idx][tight][last][slast][lz][crr];
11
12        int lim = (tight) ? s[idx] - '0' : 9;
13        long long cnt = 0;
14
15        for (int i = 0; i <= lim; i += 1) {
16            int nxt_tight = (tight && (s[idx] - '0') == i);
17            int nxt_lz = (lz && !i);
18
19            if (i == 0 && lz) {
20                cnt += solve(s, nxt_tight, idx + 1, last, slast, 1, crr);
21                continue;
22            }
23            if (last == -1) {
24                cnt += solve(s, nxt_tight, idx + 1, i, -1, nxt_lz, crr);
25                continue;
26            }
27
28            if (slast == -1) {
29                cnt += solve(s, nxt_tight, idx + 1, last, i, nxt_lz, crr);
30                continue;
31            }
32
33            int okva = ((last < slast && slast > i) || (last > slast && slast < i));
34
35            cnt += solve(s, nxt_tight, idx + 1, slast, i, nxt_lz, crr + okva);
36        }
37        if (last >= 0 && slast >= 0) 
38            return dp[idx][tight][last][slast][lz][crr] = cnt;
39        return cnt;
40    }
41
42    long long totalWaviness(long long num1, long long num2) {
43        string l = to_string(num1 - 1);
44        string r = to_string(num2);
45        /*
46            120 - 130
47
48             0 - 130 -
49        */
50        memset (dp, -1, sizeof(dp));
51        long long a = solve(r, 1, 0, -1, -1, 1, 0);
52      
53        memset (dp, -1, sizeof(dp));
54        long long b = solve(l, 1, 0, -1, -1, 1, 0);
55
56        cout << a << " " << b << " ";
57        return a - b;
58    }
59};