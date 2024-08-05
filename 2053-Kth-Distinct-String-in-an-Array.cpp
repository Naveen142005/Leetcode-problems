class Solution {
public:
    struct Mymap {
        string s;
        int c;
    };
    string kthDistinct(vector<string>& arr, int k) {
        ios_base::sync_with_stdio(false);
        unordered_map<string, int> mp;
        struct Mymap map__[arr.size()];
       
        for (int i = 0; i < arr.size(); i++) mp[arr[i]] = -1 , map__[i].c = -1;
        
        for (int i = 0; i < arr.size(); i++) 
            if (mp[arr[i]] == -1) 
                mp[arr[i]] = i, map__[i].s = arr[i] , map__[i].c = 1;
            else 
                map__[mp[arr[i]]].c += 1;
            
        string ans = "";

        for (int i = 0 ; (i < arr.size() && k > 0) ; i++ ) {
            if (map__[i].c == 1)
                k--;
            if (!k) 
                ans = map__[i].s;
        }
        return ans;
    }
};