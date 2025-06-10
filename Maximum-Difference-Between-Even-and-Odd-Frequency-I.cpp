class Solution {
public:
    int maxDifference(string s) {

        int fq[26] = {0};

        for (char i : s) fq[i - 'a'] += 1;

        int odd_mx = INT_MIN , even_mn = INT_MAX;

        for (int i = 0 ; i < 26 ; i += 1) {
            if (!fq[i]) continue;
            if (fq[i] & 1) 
                odd_mx = max (fq[i] , odd_mx);
            else 
                even_mn = min (fq[i] , even_mn);
            
        }
       return odd_mx - even_mn;
    }
};