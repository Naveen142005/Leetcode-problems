class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int fq[256] = {0}, ss = s.size(), p = 0, mx = 0, cnt = 0, i = 0;

        while (i < ss) {
            if (fq[s[i]]) {
                mx = max(cnt, mx);
                cnt -= fq[s[p]];
                fq[s[p]] -= 1;
                p += 1;
            } else {
                fq[s[i]] += 1;
                cnt += 1;
                i += 1;
            }
        }

        return max(mx, cnt);
    }
};
