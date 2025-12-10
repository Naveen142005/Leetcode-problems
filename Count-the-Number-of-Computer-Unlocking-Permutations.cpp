1class Solution {
2public:
3    int countPermutations(vector<int>& complexity) {
4        long long ss = complexity.size();
5        long long fact = 1;
6        const long long mod = 1e9 + 7;
7        long long minimum = min_element(complexity.begin(), complexity.end()) - complexity.begin();
8        // cout << minimum;
9        if (minimum != 0)  return 0;
10        long long cnt = 0, i;
11        int mx = complexity[minimum];
12        for (i = 0; i < ss - 1; i += 1) {
13            if (mx == complexity[i]) cnt += 1;
14
15            fact = (fact * (i + 1)) % mod;
16        }
17
18            if (mx == complexity[i]) cnt += 1;
19            return (cnt > 1) ? 0: (int) fact;
20        // return (int) fact;
21    }
22};