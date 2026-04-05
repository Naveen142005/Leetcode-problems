1class Solution {
2public:
3    bool judgeCircle(string moves) {
4        int cnt = 0;
5        int arr [2] = {0};
6        for (auto i: moves) {
7            if (i == 'U') arr[0] += 1;
8            else if (i == 'D') arr[0] -= 1;
9            else if (i == 'R') arr[1] += 1;
10            else arr[1] -= 1;
11        }
12        return (arr[0] == 0 && arr[1] == 0);
13    }
14};