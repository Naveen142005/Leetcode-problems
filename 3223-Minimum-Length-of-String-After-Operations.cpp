class Solution {
public:
    int minimumLength(string s) {
        vector<int> fq(26, 0);
        for (auto& i : s)
            fq[i - 'a'] += 1;
        int cnt = 0;
        for (int i = 0; i < 26; i += 1)
            if (fq[i])
                cnt = fq[i] & 1 ? cnt + 1 : cnt + 2;

        return cnt;
    }
};