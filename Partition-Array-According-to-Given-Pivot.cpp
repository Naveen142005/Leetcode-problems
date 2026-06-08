1class Solution {
2public:
3    vector<int> pivotArray(vector<int>& nums, int pivot) {
4        int n = nums.size();
5        vector<int> res(n);
6        int l = 0, r = n - 1;
7        for (int i = 0, j = n - 1; i < n; ++i, --j) {
8            if (nums[i] < pivot) res[l++] = nums[i];
9            if (nums[j] > pivot) res[r--] = nums[j];
10        }
11        for (int i = l; i <= r; ++i) res[i] = pivot;
12        return res;
13    }
14};