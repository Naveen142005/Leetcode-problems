class Solution {
public:
    bool fun (string a , string b) {
        int ss = a.size();
        if (ss != b.size()) return false;
        bool t = true;
        for (int i = 0 ; i < ss ; i += 1) {
            if (a[i] != b[i]) {
                if (!t) return false;
                t = false;
            }
        }
        return true;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {

        int _y = 0 ,mx = -1, ss = words.size() , st = -1;
        vector<int> dp(ss + 1 , 1) , idx (ss , -1);

        for (int i = ss - 2 ; i >= 0 ; i -= 1) {
             st = -1;
            for (int j = i + 1 ; j < ss ; j += 1) {
                if (groups[i] != groups[j] && fun (words[i] , words[j])) {
                        if (dp[i] < dp[j] + 1 ) {
                            dp[i] = dp[j] + 1;
                            st = j;
                        }
                }
            }
            idx[i] = st;
            if (mx < dp[i]) {
                mx = dp[i];
                _y = i;
            }
        }
        vector<string> ans;
        int i = _y;
        while (i != -1) {
            ans.push_back (words[i]);
            i = idx[i];
        }
        return ans;
    }
};
