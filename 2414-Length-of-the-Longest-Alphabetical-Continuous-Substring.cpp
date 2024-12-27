class Solution {
public:
    int longestContinuousSubstring(string s) {
        int i = 0 , j = 1 , cnt = 1;
        int ss = s.size();
        int mx = INT_MIN;
        while (j < ss) {
            if (s[j] - 1== s[j - 1]) {
                cnt += 1;
            }
            else {
                mx = max (cnt , mx);
                cnt = 1;
            }
            j += 1;
        }
        return max (mx, cnt);
    }
};