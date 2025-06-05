class Solution {
public:
    
    int ss , all;
    using t = tuple <int , int , int>;
 
    int find (vector<vector<int>>& graph , queue<t>& q , vector<vector<int>>& dict) {
        // vector<vector<vector<int>>> dict ()
        // cout << "f";
        while (q.size()) {
            // cout << "f";
            auto [idx , cnt , mask] = q.front();
            q.pop();
            if (all == mask) {
           
                return cnt;
            }

            mask = (mask | (1 << idx));

            if (dict[idx][mask] <= cnt) continue;
            dict[idx][mask] = cnt;

            for (int i : graph[idx]) {
                q.push ({i , cnt + 1 , mask});
            }

        }
        return INT_MAX;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        // if (!graph.size())
         ss = graph.size();
         all = (1 << ss) - 1;
        int mx= INT_MAX;
            queue <t> q;
        for (int i = 0 ; i < ss ; i += 1) {
            vector<vector<int>> dict (ss , vector<int> (all + 1 , INT_MAX));
            q.push({i , 0 , 0});
            mx = min (mx , find(graph , q , dict));
            while (q.size()) q.pop();
        }
        return mx == INT_MAX ? 0 : mx - 1;


    }
};