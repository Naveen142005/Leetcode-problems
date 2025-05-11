class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int cnt = 0;
        int st = 0, i = 0 , ss = arr.size();
        if (ss < 3) return false;
        while (i < 3) {
            if (arr[i++] & 1)
                cnt += 1;
        }
        if (cnt == 3)
            return true;
        int j = i;
        while(j < ss) {
            if (arr[st++] & 1)
                cnt -= 1;
            if (arr[j++] & 1)
                cnt += 1;
            if (cnt == 3)
                return true;
        }
        return false;
    }
};