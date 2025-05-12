class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;

        for (int i : nums)
            mp[i] += 1;

        int i = 0, ss = nums.size();

        while (nums[i] == 0)
            i += 1;
        if (i >= ss) return {};
        int st = nums[i] * 100;
        int end = nums[ss - 1] * 100 + 100;
        if (end >= 1000) end = 999;

        vector<int> ans;
        vector<int> t(10, 0);
        while (st <= end) {
            int num = st;

            while (num) {
                t[num % 10] += 1;
                num /= 10;
            }
            bool f = true;

            num = st;

            while (num) {

                if (t[num % 10] > mp[num % 10]) {
                    f = false;
                    break;
                }
                num /= 10;
            }
            if (f)
                ans.push_back(st);
            fill(t.begin(), t.end(), 0);
            st += 2;
        }
        return ans;
    }
};