1class Solution {
2public:
3    string processStr(string s) {
4        string res = "";
5        ios::sync_with_stdio(false);
6        cin.tie(nullptr);
7        
8        for (auto& i: s) {
9            if (i == '*') {
10                res.pop_back();
11            }
12
13            else if (i == '#') {
14                res += res;
15            }
16
17            else if (i == '%') {
18                reverse (res.begin(), res.end());
19            }
20            else {
21                res += i;
22            }
23        }
24
25        return res;
26    }
27};