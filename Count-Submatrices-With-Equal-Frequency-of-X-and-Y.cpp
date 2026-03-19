1class Solution {
2public:
3    int numberOfSubmatrices(vector<vector<char>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        vector<vector<int>>X (m, vector<int> (n, 0));
8        vector<vector<int>>Y (m, vector<int> (n, 0));
9
10        // int cnt = (grid[0][0] == 'X');
11
12        // if (!cnt)
13            // return 0;
14
15        X[0][0] = (grid[0][0] == 'X');
16        Y[0][0] = (grid[0][0] == 'Y');
17
18        int cnt = 0;
19
20        for (int i = 1; i < m; i += 1) {
21            if (grid[i][0] == 'X') X[i][0] = 1;
22            else if (grid[i][0] == 'Y') Y[i][0] = 1;
23
24            X[i][0] += X[i - 1][0];
25            Y[i][0] += Y[i - 1][0];
26
27            if (X[i][0] == Y[i][0] && X[i][0] >= 1) cnt += 1;
28           
29        }
30
31        for (int i = 1; i < n; i += 1) {
32            if (grid[0][i] == 'X') X[0][i] = 1;
33            else if (grid[0][i] == 'Y') Y[0][i] = 1;
34
35            X[0][i] += X[0][i - 1];
36            Y[0][i] += Y[0][i - 1];
37
38            if(X[0][i] == Y[0][i] && X[0][i] >= 1) cnt += 1;
39         
40            // else break;
41        }
42        for (int i = 1; i < m; i += 1) {
43            for (int j = 1; j < n; j += 1) {
44                if (grid[i][j] == 'X') X[i][j] = 1;
45                else if (grid[i][j] == 'Y') Y[i][j] = 1;
46
47                X[i][j] +=
48                    (X[i][j - 1] + X[i - 1][j]) - X[i - 1][j - 1];
49                Y[i][j] +=
50                    (Y[i][j - 1] + Y[i - 1][j]) - Y[i - 1][j - 1];
51
52                if (X[i][j] == Y[i][j] && X[i][j] >= 1) cnt += 1;
53                
54            }
55        }
56        return cnt;
57    }
58};