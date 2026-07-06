class Solution {
public:
    int dp[101][101][101][2][2];
    const int mod = 1e9 + 7;
    int solve (string& word1, string& word2, int i, int j, int k, string& target, bool a, bool b) {

        if (k >= target.size() && a && b) return a && b;
        long long res = 0;
        if (dp[i][j][k][a][b] != -1) return dp[i][j][k][a][b];
        for (int x = i; x < word1.size(); x += 1) {
            if (word1[x] == target[k]) {
                res += ((solve (word1, word2, x + 1, j, k + 1, target, true, b)) % mod);
            }
        }
        for (int y = j; y < word2.size(); y += 1) {
            if (word2[y] == target[k]) {
                res += ((solve (word1, word2, i, y + 1, k + 1, target, a, true)) % mod);
            }
        }
        return dp[i][j][k][a][b] = res % mod;
    }
    int interleaveCharacters(string word1, string word2, string target) {
        memset (dp, -1, sizeof(dp));
        return solve (word1, word2, 0, 0, 0, target,  false, false);
    }
};