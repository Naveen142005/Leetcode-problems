1class Solution {
2public:
3    long long countCommas(long long n) {
4        long long ans = 0;
5        if (n >= 1e3) ans +=  n - 1e3 + 1;
6        if (n >= 1e6) ans +=  n - 1e6 + 1;
7        if (n >= 1e9) ans +=  n - 1e9 + 1;
8        if (n >= 1e12) ans +=  n - 1e12 + 1;
9        if (n >= 1e15) ans +=  n - 1e15+ 1;
10        return ans;
11    }
12};