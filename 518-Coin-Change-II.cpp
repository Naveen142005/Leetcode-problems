class Solution {
public:
    int solve (vector<int>& coins, int amount ,  vector<vector<int>>& dp, int idx) {
         if (idx == 0) {
            if (amount % coins[0] == 0) 
                return 1;
            return 0;
        }

        if (amount < 0)
            return 0;

        if (dp[idx][amount] != -1)
            return dp[idx][amount];

       
        return dp[idx][amount] =  solve(coins, amount - coins[idx], dp, idx) + solve(coins, amount, dp, idx - 1);

    }
    int change(int amount, vector<int>& coins) {
        int ss = coins.size();
        vector<vector<int>>dp(ss + 1 ,vector<int>(amount + 1 , -1));
        return solve (coins , amount ,  dp , ss - 1);
        
    }
};