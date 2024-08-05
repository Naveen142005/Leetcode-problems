class Solution {
public:

    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        ios_base::sync_with_stdio(false);
        for (auto& i : arr) 
            if (!mp[i]) mp[i] =1;
            else mp[i]++;
        

        for (auto& i : arr) {
            if (mp[i] == 1) k--;
            if (!k) return i;
        }
        return "";
    }
};