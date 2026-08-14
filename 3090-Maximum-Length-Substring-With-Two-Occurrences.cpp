class Solution {
public:
    int maximumLengthSubstring(string s) {
        int fq[26] = {0};

        int st = 0;
        int n = s.size();
        int mx = 0;
        for (int i = 0; i < n; i += 1) {
            fq[s[i] - 'a'] += 1;

            while (fq[s[i] - 'a'] > 2) {
                fq[s[st] - 'a'] -= 1;
                st += 1;
            }
            mx = max (mx, i - st + 1);
        }
        return mx;
    }
};