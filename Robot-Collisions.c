1class Solution {
2public:
3    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
4        
5        int n = positions.size();
6
7        vector<tuple<int,int,int,char>> mp;
8
9        for (int i = 0; i < n; i += 1) {
10            mp.push_back({positions[i], i, healths[i], directions[i]});
11        }
12
13        sort(mp.begin(), mp.end());
14
15        vector<tuple<int,int,char>> stk;
16
17        for (auto [pos, idx, health, dir] : mp) {
18            
19            bool removed = false;
20
21            while (stk.size() && get<2>(stk.back()) == 'R' && dir == 'L') {
22                int currHealth = get<1>(stk.back());
23
24                if (currHealth == health) {
25                    stk.pop_back();
26                    removed = true;
27                    break;
28                }
29                else {
30                    if (currHealth > health) {
31                        removed = true;
32                        get<1>(stk.back()) = currHealth - 1;
33                        break;
34                    }
35                    else {
36                        health -= 1;
37                        stk.pop_back();
38                    }
39                }
40            }
41
42            if (!removed) {
43                stk.push_back({idx, health, dir});
44            }
45        }
46        
47        int ss = stk.size();
48        vector<int> ans(ss);
49
50        sort(stk.begin(), stk.end());
51
52        for (int i = 0; i < ss; i += 1) {
53            ans[i] = get<1>(stk[i]);
54        }
55
56        return ans;
57    }
58};