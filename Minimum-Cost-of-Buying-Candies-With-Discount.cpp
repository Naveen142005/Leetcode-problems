1class Solution {
2public:
3    int minimumCost(vector<int>& cost) {
4        sort (cost.rbegin(), cost.rend());
5        int ans = 0;
6        int sum = 0;
7        int cnt = 0;
8        for (auto& i: cost) {   
9            if (cnt && !(cnt & 1) && i <= sum) {
10                sum = 0;
11                continue;
12            }
13            cnt += 1;
14            sum += i;
15            ans += i;
16        }
17        return ans;
18    }
19};