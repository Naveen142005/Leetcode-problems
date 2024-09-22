class Solution {
public:
    struct cmp{
        bool operator() ( pair <int,int>& a , pair <int,int>& b ){
            if (a.second != b.second)   return a.second < b.second;
            else   return a.first < b.first;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {

        ios_base::sync_with_stdio(0);

        unordered_map<int, int> mp;

        for (auto i : nums) mp[i]++;

        priority_queue < pair<int,int> , vector< pair<int,int> > , cmp > pq(mp.begin(), mp.end());

        vector<int> ans;

        while (k--) ans.push_back((pq.top().first)), pq.pop();

        return ans;
    }
};