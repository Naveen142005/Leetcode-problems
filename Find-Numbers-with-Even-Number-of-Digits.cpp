class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (int i : nums) if (!(((int)(log10(i) + 1)) & 1)) cnt += 1;
        return cnt;
    }
};