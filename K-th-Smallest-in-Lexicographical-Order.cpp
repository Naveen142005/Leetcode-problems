class Solution {
public:
    long subFunction (long c , long n) {
        long nei = c + 1;
        long ans = 0;
        while (c <= n) {
            ans += min(nei , n + 1)  -c;
            c *= 10 , nei *= 10;  
        }
        return ans;
    }
    int findKthNumber(int n, int k) {
        ios_base::sync_with_stdio(0);
        long i = 1 , c = 1 , s;
        while ( i < k) {
            s = subFunction(c , n);
            if (i + s <= k) c += 1 , i += s;
            else c *= 10 , i += 1;
        }
        return (int)c;
    }
};