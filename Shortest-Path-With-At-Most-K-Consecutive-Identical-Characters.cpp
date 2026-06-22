1class Solution {
2public:
3    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
4        using t = tuple <int, int, int>; // weight, idx, k
5        priority_queue <t, vector<t>, greater<> > pq;
6
7        // vector <int> dist (n, INT_MAX);
8        vector<vector<int>> dist(n, vector<int> (51, INT_MAX));
9        pq.push ({0, 0, 1});
10        dist[0][1] = 0;
11
12        vector<vector<pair<int,int>>> adj (n);
13
14        for (auto& i: edges) {
15            adj[i[0]].push_back ({i[1], i[2]});
16        }
17
18        while (!pq.empty()) {
19            auto [w, idx, k_val] = pq.top();
20            pq.pop();
21            // cout << w << " " << idx << " " << k_val  << endl;
22            
23            for (auto& i: adj[idx]) {
24
25                if (labels[i.first] == labels[idx]) {
26                    if (k_val + 1 <= k && dist[idx][k_val] + i.second < dist[i.first][k_val + 1]) {
27                        dist[i.first][k_val + 1] = dist[idx][k_val] + i.second;
28                        pq.push ({dist[i.first][k_val + 1], i.first, k_val + 1});
29                    }
30                }
31                else {
32                    if (dist[idx][k_val] + i.second < dist[i.first][1]) {
33                        dist[i.first][1] = dist[idx][k_val] + i.second;
34                        pq.push ({dist[i.first][1], i.first, 1});
35                    }
36                }
37            }
38        }
39
40        int mx = INT_MAX;
41        for (int i = 1; i <= k; i += 1) {
42            mx = min(dist[n - 1][i], mx);
43        }
44        return mx == INT_MAX ? -1: mx;
45    }
46};