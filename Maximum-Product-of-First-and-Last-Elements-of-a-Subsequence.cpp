class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int ss = nums.size();
        long long mx = LLONG_MIN;
        vector <int> arr(ss);
        m -= 1;
        arr[ss - 1] = nums[ss - 1];

        for (int i = ss - 2 ; i >= 0 ; i -= 1) 
            arr[i] = max (nums[i] , arr[i + 1]);
       
        for (int i = 0 ; i < ss - m; i += 1) 
            mx = max ((1LL * nums[i] * arr[i + m ]), mx);
        
        arr[ss - 1] = (nums[ss - 1]);

        for (int i = ss - 2 ; i >= 0 ; i -= 1) 
            arr[i] = min (arr[i + 1] , nums[i]);
        
        for (int i = 0 ; i < ss - m; i += 1) 
            mx = max ((1LL * nums[i] * arr[i + m]), mx);
        
        return mx;
    }
};