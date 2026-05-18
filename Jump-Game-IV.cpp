1class Solution {
2public:
3    int minJumps(vector<int>& arr) {
4        unordered_map <int, vector<int>> mp;
5
6        int n = arr.size();
7        for (int i = 0; i < n; i += 1) {
8            mp[arr[i]].push_back(i);
9        }
10
11        vector <int> adj[n];
12
13        for (int i = 0; i < n; i += 1) {
14            if (i + 1 < n) adj[i].push_back(i + 1);
15            if (i - 1 >= 0) adj[i].push_back(i - 1);
16
17            // for (auto& x: mp[arr[i]]) {
18            //     if (i != x) {
19            //         adj[i].push_back(x);
20            //     }
21            // }
22        }
23
24 
25        queue <pair<int,int>> q;
26        vector<bool> visisted(n, false);
27
28        q.push({0,0});
29        visisted[0] = true;
30        
31        while (q.size()) {
32            auto [cnt, idx] = q.front();
33            q.pop();
34
35            if (idx == n - 1) {
36                return cnt;
37            }
38            visisted[idx] = true;
39
40            for (auto& i: mp[arr[idx]]) {
41                if (!visisted[i] && i != idx) {
42                    q.push({cnt + 1, i});
43                }
44            }
45
46            mp[arr[idx]].clear();
47            
48            for (auto& i: adj[idx]) {
49                if (!visisted[i]) {
50                    q.push({cnt + 1, i});
51                }
52            }
53
54        }
55
56        return -1;
57    }
58};