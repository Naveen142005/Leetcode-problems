1class Solution {
2public:
3    bool isOk(string& s1, string& s2) {
4        int i = 0;
5        int j = 0;
6
7        bool isone = false;
8        while (true) {
9            if (i == s1.size() && j == s2.size())
10                return true;
11            if (s1[i] == s2[j]) {
12                i += 1;
13                j += 1;
14            }
15
16            else {
17                if (!isone) {
18                    j += 1;
19                    isone = true;
20                } else {
21                    return false;
22                }
23            }
24        }
25        return false;
26    }
27
28    int longestStrChain(vector<string>& words) {
29        sort(words.begin(), words.end(),
30             [&](string s1, string s2) { return s1.size() < s2.size(); });
31
32        int n = words.size();
33        vector<int> dp(n + 1, 1);
34
35        int ans = 1;
36        for (int i = n - 2; i >= 0; i -= 1) {
37
38            int is = words[i].size();
39            int cnt = 0;
40
41            for (int j = i + 1; j < n; j += 1) {
42                int js = words[j].size();
43
44                if (is == js)
45                    continue;
46                else if (js - is > 1)
47                    break;
48
49                else {
50                    if (isOk(words[i], words[j])) {
51                        cnt = max(dp[j], cnt);
52                    }
53                }
54            }
55
56            dp[i] = max(dp[i], dp[i] + cnt);
57            ans = max(dp[i], ans);
58        }
59
60        return ans;
61    }
62};