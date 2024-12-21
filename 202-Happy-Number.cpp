class Solution {
public:
    bool isHappy(int n) {
        int cnt = 0;
        int stop = n;
        long long temp = n;
        if (n == 7 || n == 1) return true;
        if (n < 10) return false;
        unordered_map <int,int> mp;
        while (n > 0) {
            long sum = 0;
            while (temp > 0) {
                sum += (temp % 10) * (temp % 10);
                temp /= 10;
            }
            if (mp[sum]) return false;
            mp[sum] = 1;
            cnt += 1;
            if (cnt >= stop || sum == stop) return false;
            // cout << sum << endl;
            if (sum == 1) return true;
            n = sum;
            temp = sum;
        }
        return false;
    }
};