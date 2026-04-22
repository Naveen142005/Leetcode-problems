1class Solution {
2public:
3    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
4        int ql = queries.size();
5        int dl = dictionary.size();
6        
7        vector<string> result;
8        
9        for (int i = 0; i < ql; i++) {
10            string word = queries[i];
11            int mx = INT_MAX;
12            
13            for (int j = 0; j < dl; j++) {
14                string wd = dictionary[j];
15                int cnt = 0;
16                
17                for (int k = 0; k < wd.size(); k++) {
18                    if (word[k] != wd[k]) {
19                        cnt++;
20                    }
21                    if (cnt > 2) break;
22                }
23                
24                mx = min(cnt, mx);
25            }
26            
27            if (mx <= 2) {
28                result.push_back(word);
29            }
30        }
31        
32        return result;
33    }
34};