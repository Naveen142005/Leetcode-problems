class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int mx = INT_MIN, cnt = 0, i = 0, j = 0,ss = nums.size();

        while (j < ss) {
            if ((k && !nums[j]))
                cnt += 1, k -= 1;
            else if (nums[j])
                cnt += 1;
            else if (!k && !nums[j]) {
                mx = max(cnt, mx), cnt -= 1;
                if (!nums[i])
                    k += 1;
                i += 1;
                continue;
            }
            j += 1;
        }
        return max(mx, cnt);
    }
};