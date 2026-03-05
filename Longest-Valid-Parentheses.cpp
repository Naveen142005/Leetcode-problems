1class Solution {
2public:
3    int longestValidParentheses(string s) {
4        int n = s.size();
5        if (!n) return 0;
6        vector<int> pre (n, -1);
7        stack<pair<int, char>> stk;
8        int st = 0, end = n - 1;
9
10        while (st < n && s[st] == ')') st += 1;
11        while (end >= 0 && s[end] == '(') end -= 1;
12
13        int cnt = 0;
14        for (int i = st; i <= end; i += 1) {
15            if (stk.empty()) {
16                if (s[i] == '(') {
17                    stk.push({i, '('});
18                    continue;
19                }
20
21            }
22            if (s[i] == ')') {
23                if (!stk.empty() && stk.top().second == '(') {
24                    pre[i] = 1;
25                    // cnt += 1;
26                    pre[stk.top().first] = 0;
27                    stk.pop();
28                }
29            }
30            else if (s[i] == '(') stk.push({i, '('});
31        }
32        // for (int i : pre ) cout << i <<" ";
33        // int cnt = 0;
34        int mx = 0;
35        for (int i: pre) {
36            if (i < 0) {
37                mx = max (mx,  cnt);
38                cnt = 0;
39                continue;
40            }
41            cnt += i;
42        }
43        mx = max(mx, cnt);
44        return mx*2;
45    }
46};