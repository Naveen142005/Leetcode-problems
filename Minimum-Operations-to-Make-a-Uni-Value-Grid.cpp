1class Solution {
2public:
3    int minOperations(vector<vector<int>>& grid, int x) {
4        vector <int> temp;
5
6        for (auto& i: grid) {
7            for (auto& j: i) {
8                if (grid[0][0] % x != j % x) return -1;
9                temp.push_back(j);
10            }
11        }
12
13        sort(temp.begin(),temp.end());
14
15        int n = temp.size();
16        int mid = n/2;
17
18        int ans = 0;
19        for (int i = 0; i < n; i += 1) {
20            ans += abs(temp[i] - temp[mid]) / x;
21        }
22        
23        return ans;
24    }
25};