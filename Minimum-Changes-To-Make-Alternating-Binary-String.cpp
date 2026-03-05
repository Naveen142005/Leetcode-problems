1class Solution {
2public:
3    // int solve (string& s) {
4    //     for (int i = n - 2; i >= )
5    // }
6    int minOperations(string s) {
7        int cnt_1 = 0;
8        int cnt_2 = 0;
9        for (int i = 0; i < s.size(); i += 1) {
10            if (i & 1) {
11                if (s[i] == '0') cnt_1 += 1;
12                else cnt_2 += 1;
13            }
14            else {
15                if (s[i] == '1') cnt_1 += 1;
16                else cnt_2 += 1;
17            }
18        }
19        return min(cnt_1, cnt_2);
20        
21    }
22};