class Solution {
public:
    int freq[26];
    int n;

    string getRemaining() {
        string res = "";

        for (int i = 0; i < 26; i++) {
            res += string(freq[i], char('a' + i));
        }

        return res;
    }

    bool solve(int idx, string target, string &ans) {

        // We already formed a valid answer
        if (idx == n) {
            return ans > target;
        }

        int need = target[idx] - 'a';

        // Try characters >= target[idx]
        for (int i = need; i < 26; i++) {

            if (freq[i] == 0)
                continue;

            freq[i]--;
            ans.push_back('a' + i);

            // Case 1: Current character is greater
            // Smallest possible completion is sorted remaining chars
            if (i > need) {
                ans += getRemaining();
                return true;
            }

            // Case 2: Still equal, continue backtracking
            if (solve(idx + 1, target, ans))
                return true;

            freq[i]++;
            ans.pop_back();
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {

        n = s.size();
        memset(freq, 0, sizeof(freq));

        for (char c : s)
            freq[c - 'a']++;

        string ans = "";

        if (solve(0, target, ans))
            return ans;

        return "";
    }
};