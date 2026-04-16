1class Solution {
2public:
3    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
4        int n = nums.size();
5        unordered_map <int, vector<int>> mp;
6
7        for (int i = 0; i < n; i += 1) 
8            nums.push_back(nums[i]);
9        
10        for (int i = 0; i < nums.size(); i += 1) 
11            mp[nums[i]].push_back(i);
12
13
14        int qn = queries.size();
15        vector <int> ans (qn, -1);
16
17
18        for (int i = 0; i < qn; i += 1) {
19            int f = queries[i];
20            int r = queries[i] + n;
21
22            vector <int>& temp = mp[nums[f]];
23            if (temp.size() <= 2) continue;
24            
25            int fidx = lower_bound (temp.begin(), temp.end(), f) - temp.begin();
26            int ridx = lower_bound (temp.begin(), temp.end(), r) - temp.begin();
27
28            ans[i] = min (abs(temp[fidx] - temp[fidx + 1]), abs(temp[ridx] - temp[ridx - 1]));
29        }
30        return ans;
31    }
32};