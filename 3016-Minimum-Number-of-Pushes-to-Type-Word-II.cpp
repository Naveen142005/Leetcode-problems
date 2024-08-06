class Solution {
public:
    int minimumPushes(string word) {
        ios_base::sync_with_stdio(false); 
        vector<pair<int, char>> fq(26, {0, '0'});

        for (auto& i : word)
            fq[i - 'a'].first++, fq[i - 'a'].second = i;
        
        sort(fq.rbegin(), fq.rend());
        
        vector<int> pos(26);

        int p = 0 , cnt = 1;
        for (auto& i : fq) {
            if (i.first) {
                if (!(p % 8) && p)
                    cnt++;
                pos[i.second - 'a'] = cnt;
                
                p++;
            }
        }
   
        int ans = 0;
        for (auto& i : fq) 
            if (i.first) 
                ans = ans + (pos[i.second - 'a'] * i.first);
            
        

        return ans;
    }
};