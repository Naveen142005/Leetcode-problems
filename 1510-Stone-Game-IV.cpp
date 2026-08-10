class Solution {
public:
    inline static vector<int> temp;
    inline static bool f = true;
    inline static int sz;
    void fun() {
        f = false;
        int num = 1;
        int i = 1;
        while (num < 100001) {
            num = i * i;
            i += 1;
            temp.push_back(num);
        }
        sz = temp.size();
    }
    bool solve(int n, int flag, vector<vector<int>>& dp) {
        if (n == 0) {
            return true;
        }
        if (dp[n][flag] != -1) return dp[n][flag];

        if (flag) {
            bool res = false;
            for (int i = 0; i < sz; i += 1) {
                if (n - temp[i] < 0) break;
                res = (res || solve(n - temp[i], !flag, dp));

            }
            return dp[n][flag] = res;
        } 
        else {
            bool res = true;
            for (int i = 0; i < sz; i += 1) {
                if (n - temp[i] == 0) 
                    return false;
                if (n - temp[i] < 0) break;
                
                res = (res && solve(n - temp[i], !flag, dp));
                
            }
            return dp[n][flag] =  res;
        }
        return 1;
    }
    bool winnerSquareGame(int n) {
        if (f)
            fun();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(n, 1, dp);
        
    }
};
