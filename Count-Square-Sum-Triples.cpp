1class Solution {
2public:
3    int countTriples(int n) {
4        unordered_map <int, bool> mp;
5
6        for (int i = 0; i <= n; i += 1) 
7            mp[i * i] = 1;
8        int ans = 0;
9        for (int i = 1; i <= n; i += 1) {
10            for (int j = i + 1; j <= n; j += 1) {
11                if (mp[(i * i) + (j * j)]) ans += 2;
12            }
13        }
14
15        return ans;
16        
17    }
18};