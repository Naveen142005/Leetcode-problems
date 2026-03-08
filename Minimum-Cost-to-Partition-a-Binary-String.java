1class Solution {
2public:
3    vector <int> pre;
4    int n;
5
6    int get (int st, int end) {
7        if (st == 0) return pre[end];
8        return pre[end] - pre[st - 1];
9    }
10
11    long long solve (string& s, int e, int f, int i, int j) {
12        int noOnes = get(i, j);
13        long long without = noOnes ? (((j - i + 1) * 1L) * (e * 1L) * (noOnes * 1L)) : f;
14        
15        if ((j - i + 1) & 1) {
16            return without;   
17        }
18        int mid = (i + j) / 2;
19
20        if (i == j) return without;
21
22        long long left = solve (s, e, f, i, mid);
23        long long right = solve (s, e, f, mid + 1, j);
24
25        return min (without , (left + right));
26    }
27    
28    long long minCost(string s, int encCost, int flatCost) {
29        n = s.size();
30
31        if (n & 1) {
32            long long cnt = 0;
33            for (auto i : s) if (i != '0') cnt += 1;
34            return cnt > 0 ? cnt * (encCost * 1L) * (n * 1L) : flatCost;
35        }
36
37        pre.resize(n, 0);
38        pre[0] = (s[0] == '1' ? 1 : 0);
39
40        for (int i = 1; i < n; i += 1) {
41            if (s[i] == '1') {
42                pre[i] = pre[i - 1] + 1;
43            }
44            else pre[i] = pre[i - 1];
45        }
46
47        return solve (s, encCost, flatCost, 0, n- 1);
48    }
49};