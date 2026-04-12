1
2vector<vector<int>> D(26, vector<int>(26, 0));
3int memo[305][27][27]; // 3D array to store calculated states
4void set_();
5class Solution {
6public:
7    int solve(int idx, int jdx, string& s, char previ, char prevj, int cnt) {
8        // Base case: If we have typed all letters, distance is 0
9        if (cnt == s.size()) {
10            return 0;
11        }
12
13        // Convert chars to ints for our memo array (using 26 for unplaced '-')
14        int u = (previ == '-') ? 26 : previ - 'A';
15        int v = (prevj == '-') ? 26 : prevj - 'A';
16
17        // Return saved result if we already calculated this state
18        if (memo[cnt][u][v] != -1) {
19            return memo[cnt][u][v];
20        }
21
22        int res1 = 0, res2 = 0;
23        int x = 0, y = 0;
24
25        // The letter we must type right now is at index 'cnt'
26        char target = s[cnt];
27
28        // CHOICE 1: Move Finger 1 (previ) to target
29        if (previ != '-') {
30            res1 = D[previ - 'A'][target - 'A'];
31        }
32        // We update previ to target, idx to cnt, and increment cnt
33        x = solve(cnt, jdx, s, target, prevj, cnt + 1) + res1;
34
35        // CHOICE 2: Move Finger 2 (prevj) to target
36        if (prevj != '-') {
37            res2 = D[prevj - 'A'][target - 'A'];
38        }
39        // We update prevj to target, jdx to cnt, and increment cnt
40        y = solve(idx, cnt, s, previ, target, cnt + 1) + res2;
41
42        // Save the minimum of the two choices and return it
43        return memo[cnt][u][v] = min(x, y);
44    }
45
46    int minimumDistance(string s) {
47        set_();
48
49        // Initialize memo array with -1
50        memset(memo, -1, sizeof(memo));
51
52        // We only need ONE call. Both fingers start hovering ('-').
53        int mx = solve(0, 0, s, '-', '-', 0);
54        return mx;
55    }
56};
57
58#include <bits/stdc++.h>
59using namespace std;
60
61void set_() {
62    char grid[5][6] = {{'A', 'B', 'C', 'D', 'E', 'F'},
63                       {'G', 'H', 'I', 'J', 'K', 'L'},
64                       {'M', 'N', 'O', 'P', 'Q', 'R'},
65                       {'S', 'T', 'U', 'V', 'W', 'X'},
66                       {'Y', 'Z', ' ', ' ', ' ', ' '}};
67
68    vector<pair<int, int>> pos(26);
69
70    for (int i = 0; i < 5; i++) {
71        for (int j = 0; j < 6; j++) {
72            if (grid[i][j] != ' ') {
73                int idx = grid[i][j] - 'A';
74                pos[idx] = {i, j};
75            }
76        }
77    }
78
79    for (int i = 0; i < 26; i++) {
80        for (int j = 0; j < 26; j++) {
81            auto [r1, c1] = pos[i];
82            auto [r2, c2] = pos[j];
83            D[i][j] = abs(r1 - r2) + abs(c1 - c2);
84        }
85    }
86}
87