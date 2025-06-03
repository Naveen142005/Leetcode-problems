const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
class Solution {
public:
    int shortestPathAllKeys(vector<string>& s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        priority_queue<tuple<int, int, int, int>, 
                       vector<tuple<int, int, int, int>>, 
                        greater<tuple<int, int, int, int>>> q;

        int m = s.size();
        int n = s[0].size();

        int keys = 0, st, end;
        for (int i = 0; i < m; i += 1) {
            for (int j = 0; j < n; j += 1) {
                if (s[i][j] == '@')
                    st = i, end = j;
                else if (islower(s[i][j])) {
                    s[i][j] = (char)((s[i][j] - 'a') + '0');
                    keys += 1;
                }
            }
        }

        int fullbit = (1 << keys) - 1;
        int visited[31][31][1 << 6] = {0};
        q.push({0, st, end, 0});

        while (q.size()) {
            auto [cnt, idx, jdx, mask] = q.top();
            q.pop();
            char ch = s[idx][jdx];
            if (mask == fullbit)
                return cnt - 1;

            if (visited[idx][jdx][mask])
                continue;
            visited[idx][jdx][mask] = 1;

            if (isdigit(ch)) 
                mask |= (1 << (ch - '0'));
            
            else if (isalpha(ch) && (!(mask & (1 << (ch - 'A')))) || (ch == '#')) 
                continue;

            for (int i = 0; i < 4; i += 1) {
                int ni = idx + dir[i][0];
                int nj = jdx + dir[i][1];

                if (ni >= 0 && nj >= 0 && ni < m && nj < n)
                    q.push({1 + cnt, ni, nj, mask});
            }
        }
        return -1;
    }
};
