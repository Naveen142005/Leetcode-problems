1class Solution {
2    public int minimumIndex(int[] capacity, int itemSize) {
3        int ans = -1;
4        int idx = -1;
5        for (int i = 0; i < capacity.length; i += 1) {
6            if (capacity[i] >= itemSize) {
7                if (ans == -1) {
8                    ans = capacity[i];
9                    idx = i;
10                }
11                else {
12                    if (ans > capacity[i]) {
13                        ans = capacity[i];
14                        idx = i;
15                    }
16                }
17            }
18        }
19        return idx;
20    }
21}