class Solution {
public:
    void findSubArray(int n, vector<long long int>& pq, vector<int> nums) {
        for (int i = 0; i < n; i++) {
            long long int temp = 0;
            for (int j = i; j < n; j++) {
                temp += nums[j];
                pq.push_back(temp);
            }
        }
        sort(pq.begin(), pq.end());
    }
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // ios_base::sync_with_stdio(0);

        int return_value = 1000000007;
        vector<long long int> pq;
        findSubArray(n, pq, nums);
        long sum = 0;
        for (int i = left - 1; i < right; i++) 
            sum = (sum + pq[i]) % return_value;
        

        return static_cast<int>(sum);
    }
};