class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int cnt = 0;
        for (int i = 0 ; i < k ; i += 1) cnt += nums[i];

        int mx =  cnt;

        int i = 0 , j = k;
        while (j < nums.size()) {
            cnt -= nums[i];
            cnt += nums[j];
            mx = max (mx ,cnt);
            i += 1 , j += 1;
        }
        return (double) mx * 1.0 / k;
    }
};