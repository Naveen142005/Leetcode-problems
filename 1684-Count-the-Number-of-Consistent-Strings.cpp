class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios_base::sync_with_stdio(false);
        vector<bool> fq(26, false);
        int cnt = 0;
        for (auto _i : allowed)
            fq[_i - 'a'] = true;
        for (auto _word : words) {
            bool _flag = true;
            for (auto _char : _word) {
                if (!fq[_char - 'a']) {
                    _flag = false;
                    break;
                }
            }
            if (_flag) cnt++;
        }
        return cnt;
    }
};