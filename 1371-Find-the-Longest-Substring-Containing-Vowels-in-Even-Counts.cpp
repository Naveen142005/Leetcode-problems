class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map <int, int> mp;

        int curr = 0;
        mp[curr] = -1;
        int idx = 0, mx = 0;

        for (auto& i: s) {
            if (i == 'a')      curr ^= (1 << 0);
            else if (i == 'e') curr ^= (1 << 1);
            else if (i == 'i') curr ^= (1 << 2);
            else if (i == 'o') curr ^= (1 << 3);
            else if (i == 'u') curr ^= (1 << 4);

            if (mp.find(curr) != mp.end()) {
                mx = max (mx, abs(idx - mp[curr]));
            }
            else mp[curr] = idx;

            idx += 1;
        }
        return mx;
    }
};