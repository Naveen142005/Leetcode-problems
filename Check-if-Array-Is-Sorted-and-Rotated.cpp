1class Solution {
2public:
3    bool check(vector<int>& nums) {
4        int n = nums.size();
5        
6    
7        vector<int> mp;
8        int mx = *min_element(nums.begin(), nums.end());
9        int idx = 0;
10
11        for (int i = 0; i < n; i += 1) {
12            if (mx == nums[i]) 
13                mp.push_back(i);
14        }
15        vector<int> temp = nums;
16        sort(temp.begin(), temp.end());
17
18        // for (auto)
19       
20
21        for (auto& x: mp) {
22            bool flag = true;
23            for (int i = 0; i < n; i += 1) {
24                if (nums[(i + x) % n] == temp[i]) continue;
25                else {
26                    flag = false;
27                    break;
28                }
29            }
30            if (flag) return true;
31            
32        }
33        
34        return false;
35    }
36};