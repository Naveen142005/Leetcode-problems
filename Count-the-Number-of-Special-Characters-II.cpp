1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        int fq[26] = {0};
5        int fq1[26] = {0};
6        int cnt = 0;
7
8        for (auto& i: word) {
9            if (islower(i)) {
10                fq[i - 'a'] += 1;
11            }
12        }
13
14        for (auto& i: word) {
15            if (isupper(i)) {
16                if (fq[i - 'A'] <= fq1[i - 'A'] && fq[i - 'A']) {
17                    cnt += 1;
18                }
19                fq[i - 'A'] = 0;
20                fq1[i - 'A'] = 0;
21            }
22            if (islower(i)) fq1[i - 'a'] += 1;
23        }
24        return cnt;
25    }
26};