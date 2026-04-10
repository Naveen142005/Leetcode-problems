1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4        unordered_map <int, vector<int>> mp;
5
6        int ss = nums.size();
7
8        for (int i = 0; i < ss; i += 1) 
9            mp[nums[i]].push_back(i);
10        int mx = INT_MAX;
11        
12        for (auto& [idx, num]: mp) {
13            if (num.size() < 3) continue;
14
15            for (int i = 0;  i < num.size() - 2; i += 1) {
16                int x = num[i];
17                int y = num[i + 1];
18                int z = num[i + 2];
19
20                mx = min (mx,abs(x - y) + abs(y - z) + abs(z - x));
21                
22            }
23        }
24        return mx == INT_MAX ? -1 : mx;
25    }
26};