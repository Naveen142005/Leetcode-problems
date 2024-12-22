class Solution {
public:
    void solve(vector<vector<bool>>& visi, vector<vector<char>>& board,
               string& word, int index, int i, int j, bool& answer, int& m,
               int& n) {
        if (index == word.size())
            answer = true;
        if (!answer && word[index] == board[i][j]) {
            if (j + 1 < n && !visi[i][j] && !answer) {
                visi[i][j] = true;
                solve(visi, board, word, index + 1, i, j + 1, answer, m, n);
                visi[i][j] = false;
            }
            if (j - 1 >= 0 && !visi[i][j] && !answer) {
                visi[i][j] = true;
                solve(visi, board, word, index + 1, i, j - 1, answer, m, n);
                visi[i][j] = false;
            }
            if (i + 1 < m && !visi[i][j] && !answer) {
                visi[i][j] = true;
                solve(visi, board, word, index + 1, i + 1, j, answer, m, n);
                visi[i][j] = false;
            }
            if (i - 1 >= 0 && !visi[i][j] && !answer) {
                visi[i][j] = true;
                solve(visi, board, word, index + 1, i - 1, j, answer, m, n);
                visi[i][j] = false;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        if (m == 1 && n == 1 && word.size() == 1)
            return board[0][0] == word[0];

        vector<vector<bool>> v(m, vector<bool>(n, false));
        bool ans = false;

        for (int i = 0; i < m; i += 1) {
            for (int j = 0; j < n; j += 1) {
                if (ans)
                    return ans;
                solve(v, board, word, 0, i, j, ans, m, n);
            }
        }
        return ans;
    }
};