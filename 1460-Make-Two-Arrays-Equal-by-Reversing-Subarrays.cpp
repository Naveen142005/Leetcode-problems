class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        ios_base::sync_with_stdio(false);
       
        unordered_map<int,int>mp;

        for (auto& i : arr) 
            if (!mp[i]) mp[i] = 1;
            else mp[i] += 1;
        
        for (auto& i : target) 
            mp[i] -=  1;

        for (auto& i : arr) 
            if (mp[i]) 
                return false;
        return true;
    }
};