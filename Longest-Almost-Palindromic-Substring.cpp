1#include <algorithm>
2#include <string>
3
4using namespace std;
5
6class Solution {
7public:
8    bool isvalid(string& s, int i, int j) {
9        while (i <= j) {
10            if (s[i] != s[j])
11                return false;
12            i += 1;
13            j -= 1;
14        }
15        return true;
16    }
17
18    int solve(string s) {
19        int n = s.size();
20        int ans = 0;
21
22        for (int i = 0; i < n; i += 1) {
23            for (int j = i + 1; j < n; j += 1) {
24                int len = j - i + 1;
25                int l = i, r = j;
26                int miss = 0;
27                int mx = 0;
28                if (ans >= len)
29                    continue;
30                while (l < r) {
31                    if (s[l] == s[r])
32                        l += 1, r -= 1;
33
34                    else {
35                        miss = 1;
36                        if (isvalid(s, l + 1, r) || isvalid(s, l, r - 1))
37                            ans = max(ans, len);
38
39                        break;
40                    }
41                }
42
43                if (miss == 0) {
44                    ans = max(ans, len);
45                }
46            }
47        }
48        return ans;
49    }
50
51    int almostPalindromic(string s) { return solve(s); }
52};