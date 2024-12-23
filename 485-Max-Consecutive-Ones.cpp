class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0 , mx = INT_MIN;
        for (int i : nums) {
            if (i) cnt += 1;
            else mx = max (mx , cnt) , cnt = 0;
        }
        return max (mx , cnt);
    }
};