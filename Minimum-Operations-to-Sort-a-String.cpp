1class Solution {
2public:
3    int minOperations(string s) {
4        int ss = s.size();
5
6        queue<string> q;
7
8        string sorted = s;
9        sort(sorted.begin(),sorted.end());
10        
11        if (sorted == s) return 0;
12
13        q.push(s);
14    
15        int cnt = 0;
16
17        ios::sync_with_stdio(false);
18        cin.tie(nullptr);
19        
20
21        while (cnt < 4) {
22            cnt += 1;
23            int sz = q.size();
24
25            while (sz--) {
26                string ts = q.front();
27                string tempts = ts;
28
29                q.pop();
30
31                sort(ts.begin() + 1,ts.end());
32
33                if (ts == sorted) return cnt;
34
35                sort(tempts.begin(),tempts.end() - 1);
36
37                if (tempts == sorted) return cnt;
38
39                q.push(ts);
40                q.push(tempts);
41            }
42    
43        }
44        return -1;
45    }
46};