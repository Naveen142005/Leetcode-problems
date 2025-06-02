#define first f
#define second s
class Solution {
public:
    int minMoves(vector<string>& s, int energy) {
        int dir[4][2] = {{1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1}};
        queue<tuple<int, int, int, int, int>> q;
        // queue<vector<int>> q;
        int m = s.size(), n = s[0].size(), x, y;
        char Lcnt = '0';
        int lcnt = 0;

        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (s[i][j] == 'S') {
                    x = i, y = j;
                } else if (s[i][j] == 'L') {
                    s[i][j] = Lcnt++;
                    lcnt++;
                }
            }
        }

        if (!lcnt) return 0;
        int fullbit = (1 << lcnt) - 1;
        vector<vector<vector<int>>> dict(m, vector<vector<int>>(n, vector<int>(fullbit + 1, -1)));

        q.push({x, y, 0, energy, 0});
       

        while (!q.empty()) {
          auto t = q.front();
            int idx = get<0>(t);
            int jdx = get<1>(t);
            int cnt = get<2>(t);
            int e =   get<3>(t);
            int mask = get<4>(t);

            // int idx = t[0];
            // int jdx = t[1];
            // int cnt = t[2];
            // int e =   t[3];
            // int mask = t[4];

            q.pop();

            if (dict[idx][jdx][mask] >= e) continue;
            dict[idx][jdx][mask] = e;

            if (isdigit(s[idx][jdx])) {
                int digit = s[idx][jdx] - '0';
                mask |= (1 << digit);
                if (mask == fullbit) return cnt;
            } else if (s[idx][jdx] == 'R') e = energy;

            if (!e) continue;

            for (int i = 0 ; i < 4 ; i++) {
                int ni = idx + dir[i][0];
                int nj = jdx + dir[i][1];
                if (ni >= 0 && nj >= 0 && ni < m && nj < n && s[ni][nj] != 'X')
                    q.push({ni, nj, cnt + 1, e - 1, mask});
            }
        }

        return -1;
    }
};
