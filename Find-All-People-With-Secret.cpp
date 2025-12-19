1class Solution {
2public:
3    using int2 = pair<int, int>;
4
5    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
6        vector<vector<int2>> adj(n);
7
8        // Build adjacency list: (time, neighbor)
9        for (auto& meet : meetings) {
10            int x = meet[0], y = meet[1], time = meet[2];
11            adj[x].emplace_back(time, y);
12            adj[y].emplace_back(time, x);
13        }
14
15        vector<int> known(n, INT_MAX);
16        vector<int> result;
17
18        priority_queue<int2, vector<int2>, greater<int2>> pq;
19        pq.emplace(0, 0);
20        pq.emplace(0, firstPerson);
21
22        while (!pq.empty()) {
23            auto [time, person] = pq.top();
24            pq.pop();
25
26            if (known[person] != INT_MAX) continue;
27
28            known[person] = time;
29            result.push_back(person);
30
31            for (auto& [t, next] : adj[person]) {
32                if (known[next] == INT_MAX && t >= time) {
33                    pq.emplace(t, next);
34                }
35            }
36        }
37
38        return result;
39    }
40};
41
42auto init = []() {
43    ios::sync_with_stdio(false);
44    cin.tie(nullptr);
45    cout.tie(nullptr);
46    return 0;
47}();