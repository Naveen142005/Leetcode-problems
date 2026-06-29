1class Solution {
2public:
3    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
4        ios::sync_with_stdio(false);
5        cin.tie(nullptr);
6        
7        
8        vector <pair<int,int>> adj[n];
9
10        for (auto& i: edges) {
11            adj[i[0]].push_back({i[1], i[2]}); // edge, time
12        }
13
14        using ll = long long;
15        using t = tuple <ll, ll, int>;
16        priority_queue <t, vector <t>, greater<> > pq; // {time, currpower, idx}
17
18
19
20        vector <vector<ll>> dist (n + 1, vector<ll> (power + 1, LLONG_MAX)); 
21        dist[source][power] = 0;
22
23        pq.push({0LL, 1LL * power, source});
24
25        while (pq.size()) {
26            auto [currTime, currPower, idx] = pq.top();
27            pq.pop();
28
29            if (currPower < cost[idx]) continue;
30
31            for (auto& node: adj[idx]) {
32                int v = node.first;
33                int t = node.second;
34                int np = currPower - cost[idx];
35
36                // cout << idx << " " << currPower << " " << dist[idx][currPower] << endl;
37                // cout << v << " " << t << " " << np << endl;
38                if (dist[idx][currPower] + t < dist[v][np]) {
39                    dist[v][np] = dist[idx][currPower] + t;
40                    pq.push ({dist[v][np], np, v});
41                }
42            }
43        }
44        
45        // cout << "s";
46        ll ans = LLONG_MAX;
47        ll ans_p = -1;
48        for (int i = 0; i <= power; i += 1) {
49            if (ans >= dist[target][i]) {
50                ans = dist[target][i];
51                ans_p = max(ans_p, i * 1LL);
52                
53            }
54        }
55        // cout << "sss";
56
57        // cout << ans << " " << ans_p;
58        if (ans == LLONG_MAX) {
59            ans = -1;
60            ans_p = -1;
61        }
62        return {ans, ans_p};
63    }
64};