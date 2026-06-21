1class Solution {
2public:
3    int maxIceCream(vector<int>& costs, int coins) {
4        sort(costs.begin(),costs.end());
5        int cnt = 0;
6        for (int i: costs) {
7            if (coins - i < 0) break;
8            coins -= i;
9            cnt += 1;
10        }
11        return cnt;
12    }
13};