1class Solution {
2public:
3    int solve (vector<int>& nums, int k) {
4        unordered_map <int, int> mp;
5
6        int n = nums.size();
7        int st = 0;
8        int cnt = 0;
9        
10        for (int i = 0; i < n; i += 1) {
11            mp[nums[i]] += 1;
12            
13            while (mp.size() > k) {
14                mp[nums[st]] -= 1;
15                if (mp[nums[st]] == 0) {
16                    mp.erase(nums[st]);
17                }
18                st += 1;
19            }
20            
21            cnt += (i - st + 1);
22        }
23        return cnt;
24    }
25    int subarraysWithKDistinct(vector<int>& nums, int k) {
26        int left =  solve (nums, k);
27        // cout << '\n';
28        int right = solve (nums, k - 1);
29        cout << left << " " << right ;
30        return left - right;
31    }
32};