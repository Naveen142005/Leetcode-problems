class Solution {
public:
    bool check (vector <vector< pair<int,int> >>& adj, int mid, vector<bool>& online, long long k) {
        using t = tuple <long long, int>; // val, idx
        priority_queue <t, vector<t>, greater<> > pq;
        int n = online.size();
        
        vector<long long> dist (n, LLONG_MAX);
        dist[0] = 0;
        pq.push ({0,0});

        while(pq.size()) {
            auto [val, idx] = pq.top();
            pq.pop();
            
            if (val > dist[idx]) continue;

            if (idx == n - 1) {
                return val <= k;
            }

            
            for (auto [i, w]: adj[idx]) {
                if (w < mid) continue;
                if (!online[i]) continue;

                if (dist[idx] + w < dist[i]) {
                    dist[i] = dist[idx] + w;
                    pq.push ({dist[i], i});
                }
            }
        }
        return false;   

    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {


        int n = online.size();
        if (!online[0] || !online[n - 1]) return -1;
        vector <vector< pair<int,int> >> adj(n);

        int mx = -1;
        for (auto i: edges) {   
            adj[i[0]].push_back({i[1], i[2]});
            mx = max (mx, i[2]);
        }

        int left = 0;
        int right = mx; 
        int ans = -1;

        while (left <= right) {
            int mid = (left) + ((right - left) / 2);

            if (check(adj, mid, online, k))  {
                ans = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return ans;
    }
};