class Solution {
public:
    int countPalindromicSubsequence(string s) {
        ios_base::sync_with_stdio(false);

        int ss = s.size(), index, cnt = 0;
        ;
        vector<pair<int, int>> fq(26, {0, -1});

        for (int i = 0; i < ss; i += 1)
            fq[s[i] - 'a'].first += 1, fq[s[i] - 'a'].second = i;

        for (int i = 0; i < ss; i += 1) {
            index = fq[s[i] - 'a'].second;
            if (index != i && index != -1) {
                vector<bool> ch(26, false);
                for (int j = i + 1; j < index; j += 1) {
                    if (!ch[s[j] - 'a'])
                        cnt += 1, ch[s[j] - 'a'] = true;

                    ch.clear();
                    fq[s[i] - 'a'].second = -1;
                }
            }
        }
        return cnt;
    }
};