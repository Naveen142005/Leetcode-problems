class Solution {
public:
    int mx = -1 , ans = -1;
    void dfs_ (vector<vector<int>>& adj , int k , int &cnt , vector<int>& visited , int idx) {
        if (k <= 0){
            return;
        }
        visited[idx] = 1;
        for (int i : adj[idx]) {
            if (!visited[i]) {
                cnt += 1;
                dfs_(adj , k - 1 , cnt , visited , i);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int K = k - 1  , n = edges1.size() , m = edges2.size();
        n += 1, m += 1;
        vector<int> Ans(n , 1);
        if (!k) return Ans;
        vector<vector<int>> adj_1(n , vector<int>());
        vector<vector<int>> adj_2(m , vector<int>());
        
        for (auto i : edges1) 
            adj_1[i[0]].push_back (i[1]),
            adj_1[i[1]].push_back (i[0]);

        for (auto i : edges2) 
            adj_2[i[0]].push_back (i[1]),
            adj_2[i[1]].push_back (i[0]);
        
        vector<int> visited_1(n , 0);
        vector<int> visited_2(m , 0);
        
        for (int i = 0 ; i < m ; i += 1) {
            int cnt = 0;
            dfs_ (adj_2 , K , cnt , visited_2 , i);
            mx = max (cnt , mx);
            fill(visited_2.begin() , visited_2.end() , 0);
        }
        

        for (int i = 0 ; i < n ; i += 1) {
            ans = 0;
            dfs_ (adj_1 , k , ans , visited_1 , i);
            fill(visited_1.begin() , visited_1.end() , 0);
            Ans[i] = (ans + mx + 2);
        }
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        return Ans;


    }
};