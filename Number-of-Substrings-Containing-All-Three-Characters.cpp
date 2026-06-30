1class Solution {
2public:
3    int numberOfSubstrings(string s) {
4        int fq[3] = {0};
5        int n = s.size();
6        int st = 0;
7        int sum = 0;
8
9        for (int i = 0; i < n; i += 1) {
10            fq[s[i] - 'a'] += 1;
11
12            while (true) {
13                if (fq[0] >= 1 && fq[1] >= 1 && fq[2] >= 1) {
14                    sum += (n - i);
15                    fq[s[st] - 'a'] -= 1;
16                    st += 1;
17                }
18                else break;
19            }
20        }
21       
22        return sum;
23
24    }
25};