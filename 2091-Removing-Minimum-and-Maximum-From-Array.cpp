class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIndex = -1, maxIndex = -1;
        int mx = INT_MIN, mi = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; i += 1) {
            if (mx < nums[i]) {
                mx = nums[i];
                maxIndex = i;
            }

            if (mi > nums[i]) {
                mi = nums[i];
                minIndex = i;
            }
        }

        // cout << maxIndex << " " << minIndex << endl;

        vector <int> arr = {maxIndex, minIndex};
        sort(arr.begin(),arr.end());

        // cout << arr[0] << " " << arr[1] << endl;
        int a = arr[0] + 1 + n - arr[1];
        int b = arr[1] + 1;
        int c = n - arr[0];
        // cout << a << " " << b << " " << c;
        return min (min(a,b) , c);
    }
};